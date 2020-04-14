/*
** EPITECH PROJECT, 2020
** new_client.c
** File description:
** myftp
*/

#include "myftp.h"

client_t *new_elem_struct(int csock, char *folder_path, struct sockaddr_in cin)
{
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL)
        return (NULL);
    new_client->socket = csock;
    new_client->root_remoteness = 0;
    new_client->directory = calloc(MAX_FOLDER_SIZE, MAX_FOLDER_SIZE);
    new_client->username = calloc(MAX_BUFFER, MAX_BUFFER);
    if (new_client->username == NULL || new_client->directory == NULL)
        return (NULL);
    strcpy(new_client->directory, folder_path);
    new_client->passwd = false;
    new_client->is_set = true;
    new_client->port = ntohs(cin.sin_port);
    new_client->is_connected = false;
    return (new_client);
}

void new_client(client_t *clients[], int server_socket, \
char *folder_path, int *fd_max)
{
    int csock = 0;
    struct sockaddr_in cin;
    socklen_t len_cin = sizeof(cin);

    csock = accept(server_socket, (struct sockaddr *)&cin, &len_cin);
    printf("New connection from ip: %s, port: %d\n", \
    inet_ntoa(cin.sin_addr), ntohs(cin.sin_port));
    send_message("220 Connection established\r\n", csock);
    *fd_max += 1;
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (clients[i] == NULL) {
            clients[i] = new_elem_struct(csock, folder_path, cin);
            return;
        }
}