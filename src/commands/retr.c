/*
** EPITECH PROJECT, 2020
** retr.c
** File description:
** myftp
*/

#include "myftp.h"

void retr(char *commands, client_t *client)
{
    send_message(command_array[11].message, client->socket);
}