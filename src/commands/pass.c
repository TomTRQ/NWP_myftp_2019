/*
** EPITECH PROJECT, 2020
** pass.c
** File description:
** myftp
*/

#include "myftp.h"

void pass(char *client_pass, client_t *client, server_t server)
{
    if (!client->is_connected) {
        if (client_pass == NULL)
            client->passwd = true;
        else
            client->passwd = false;
        if (client->passwd && client->username && strcmp(client->username, "Anonymous") == 0) {
            client->is_connected = true;
            send_message("230 User logged in, proceed.\r\n", client->socket);
        } else
            send_message(command_array[1].message, client->socket);
    } else
        send_message("xxx User already connected\r\n", client->socket);
}