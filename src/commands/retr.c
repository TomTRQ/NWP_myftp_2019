/*
** EPITECH PROJECT, 2020
** retr.c
** File description:
** myftp
*/

#include "myftp.h"

void retr(char *commands, client_t *client, server_t server)
{
    send_message(command_array[11].message, client->socket);
}