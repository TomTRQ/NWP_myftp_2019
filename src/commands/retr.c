/*
** EPITECH PROJECT, 2020
** retr.c
** File description:
** myftp
*/

#include "myftp.h"
#include <fcntl.h>

void get_file(char *file, client_t *client)
{
    FILE *fp;
    struct sockaddr_in cin;
    socklen_t len_cin = sizeof(cin);
    int csock = accept(client->data_socket, (struct sockaddr *)&cin, &len_cin);

    send_message(command_array[13].message, client->socket);
    fp = popen("cat main.c", "r");
    message_loop(fp, csock);
    send_message("226 Closing data connection\r\n", client->socket);
    close(csock);
}

void retr(char *file, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("532 Need account for storing \
files\r\n", client->socket));
    if (!file)
        return (send_message("501 RETR takes a pathname as \
parameter\r\n", client->socket));
    if (open(file, O_RDONLY) == -1)
        return (send_message("550 file not found\r\n", client->socket));
    send_message(command_array[11].message, client->socket);
    get_file(file, client);
}