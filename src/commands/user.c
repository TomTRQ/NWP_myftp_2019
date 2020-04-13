/*
** EPITECH PROJECT, 2020
** user.c
** File description:
** myftp
*/

#include "myftp.h"

void user(char *client_username, client_t *client, server_t server)
{
    if (!client->is_connected) {
        strcpy(client->username, client_username);
        if (client->passwd && client_username && strcmp(client_username, "Anonymous") == 0) {
            client->is_connected = true;
            send_message("230 User logged in, proceed.\r\n", client->socket);
        } else if (client_username && strcmp(client_username, "Anonymous") == 0)
            send_message(command_array[0].message, client->socket);
        else
            send_message("501 Username invalid\r\n", client->socket);
    } else
        send_message("500 User already connected\r\n", client->socket);
}