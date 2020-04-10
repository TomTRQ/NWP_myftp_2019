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

    if (parameter) {
        send_message("xxx PWD command does not take a parameter\r\n", client->socket);
        return;
    }
    if (!folder) {
        send_message("xxx An error occured while executing the command\r\n", client->socket);
        return;
    }
    strcpy(folder, client->directory);
    strcat(folder, "\r\n");
    send_message(folder, client->socket);
    free(folder);
}