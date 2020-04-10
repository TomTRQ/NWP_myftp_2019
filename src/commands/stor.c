/*
** EPITECH PROJECT, 2020
** stor.c
** File description:
** myftp
*/

#include "myftp.h"

void stor(char *commands, client_t *client, server_t server)
{
    send_message(command_array[12].message, client->socket);
}