/*
** EPITECH PROJECT, 2020
** port.c
** File description:
** myftp
*/

#include "myftp.h"

void port(char *commands, client_t *client)
{
    send_message(command_array[8].message, client->socket);
}