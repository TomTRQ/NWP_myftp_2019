/*
** EPITECH PROJECT, 2020
** quit.c
** File description:
** myftp
*/

#include "myftp.h"

void quit(char *first_argument, client_t *client, server_t server)
{
    if (first_argument)
        return send_message("501 QUIT command has no parameter\r\n", client->socket);
    send_message(command_array[4].message, client->socket);
    close(client->socket);
    printf("Disconnection from port %d\n", client->port);
    client->is_set = false;
}