/*
** EPITECH PROJECT, 2020
** dele.c
** File description:
** myftp
*/

#include "myftp.h"

void dele(char *commands, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("530 Need connection\r\n", client->socket));
    send_message(command_array[5].message, client->socket);
}