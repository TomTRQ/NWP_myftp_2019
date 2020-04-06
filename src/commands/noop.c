/*
** EPITECH PROJECT, 2020
** noop.c
** File description:
** myftp
*/

#include "myftp.h"

void noop(char *commands, client_t *client)
{
    send_message(command_array[10].message, client->socket);
    return;
}