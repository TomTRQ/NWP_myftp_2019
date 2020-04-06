/*
** EPITECH PROJECT, 2020
** pwd.c
** File description:
** myftp
*/

#include "myftp.h"

void pwd(char *command, client_t *client)
{
    send_message(command_array[6].message, client->socket);
}