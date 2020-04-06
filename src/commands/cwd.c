/*
** EPITECH PROJECT, 2020
** cwd.c
** File description:
** myftp
*/

#include "myftp.h"

void cwd(char *pathname, client_t *client)
{
    send_message(command_array[2].message, client->socket);
    client->directory = pathname;
}