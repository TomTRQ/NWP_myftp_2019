/*
** EPITECH PROJECT, 2020
** cdup.c
** File description:
** myftp
*/

#include "myftp.h"

void cdup(char *commands, client_t *client)
{
    send_message(command_array[3].message, client->socket);
}