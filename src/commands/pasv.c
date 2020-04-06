/*
** EPITECH PROJECT, 2020
** pasv.c
** File description:
** myftp
*/

#include "myftp.h"

void pasv(char *commands, client_t *client)
{
    send_message(command_array[7].message, client->socket);
}