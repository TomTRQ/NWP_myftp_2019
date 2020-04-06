/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** myftp
*/

#include "myftp.h"

void help(char *commands, client_t *client)
{
    send_message(command_array[9].message, client->socket);
}

