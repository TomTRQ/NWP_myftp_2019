/*
** EPITECH PROJECT, 2020
** stor.c
** File description:
** myftp
*/

#include "myftp.h"
#include <fcntl.h>

void close_file_connection(int csock, int file_fd, client_t *client)
{
    close(file_fd);
    close(csock);
    send_message("226 Closing data connection\r\n", client->socket);
}

void send_file(char *file, client_t *client, int file_fd)
{
    struct sockaddr_in cin;
    socklen_t len_cin = sizeof(cin);
    int csock = accept(client->data_socket, (struct sockaddr *)&cin, &len_cin);
    char *message = calloc(MAX_BUFFER, MAX_BUFFER);

    if (message == NULL)
        return (send_message("500 Error with STOR\r\n", client->socket));
    send_message(command_array[12].message, client->socket);
    while (1) {
        if (read(csock, message, MAX_BUFFER) <= 0)
            return (close_file_connection(csock, file_fd, client));
        send_message(message, file_fd);
    }
}

void stor(char *file, client_t *client, server_t server)
{
    int file_fd = 0;

    if (!client->is_connected)
        return (send_message("530 Need account for \
storing files\r\n", client->socket));
    if (!file)
        return (send_message("501 STOR takes a pathname \
as parameter\r\n", client->socket));
    file_fd = open(file, O_WRONLY | O_CREAT, 0644);
    if (file_fd == -1)
        return (send_message("550 file not found\r\n", client->socket));
    send_file(file, client, file_fd);
}