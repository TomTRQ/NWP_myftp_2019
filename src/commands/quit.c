/*
** EPITECH PROJECT, 2020
** quit.c
** File description:
** myftp
*/

#include "myftp.h"

void quit(char *commands, client_t *client)
{
    send_message(command_array[4].message, client->socket);
    close(client->socket);
}