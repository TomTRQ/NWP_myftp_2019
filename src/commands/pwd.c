/*
** EPITECH PROJECT, 2020
** pwd.c
** File description:
** myftp
*/

#include "myftp.h"

void pwd(char *parameter, client_t *client, server_t server)
{
    char *folder = malloc(4096);

    if (!client->is_connected)
        return (send_message("530 Need connection\r\n", client->socket));
    if (parameter)
        return (send_message("501 PWD command does not take a \
        parameter\r\n", client->socket));
    if (!folder)
        return (send_message("500 An error occured while executing \
        the command\r\n", client->socket));
    strcpy(folder, client->directory);
    strcat(folder, "\r\n");
    send_message(folder, client->socket);
}