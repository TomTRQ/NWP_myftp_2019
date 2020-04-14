/*
** EPITECH PROJECT, 2020
** noop.c
** File description:
** myftp
*/

#include "myftp.h"

void noop(char *command, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("530 Need connection\r\n", client->socket));
    if (command) {
        send_message("501 NOOP does not take a parameter\r\n", client->socket);
        return;
    }
    send_message(command_array[10].message, client->socket);
}