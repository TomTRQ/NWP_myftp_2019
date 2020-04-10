/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** myftp
*/

#include "myftp.h"

void list(char *commands, client_t *client, server_t server)
{
    send_message(command_array[13].message, client->socket);
}