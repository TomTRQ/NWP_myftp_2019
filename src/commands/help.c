/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** myftp
*/

#include "myftp.h"

void help(char *command, client_t *client, server_t server)
{
    if (!command)
        send_message(command_array[9].message, client->socket);
    else {
        for (int i = 0; i < COMMAND_NUMBER; i++)
            if (strcmp(command_array[i].name, command) == 0) {
                send_message(help_array[i], client->socket);
                return;
            }
        send_message("501 Invalid HELP parameter\r\n", client->socket);
    }
}

