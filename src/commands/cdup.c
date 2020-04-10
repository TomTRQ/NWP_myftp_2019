/*
** EPITECH PROJECT, 2020
** cdup.c
** File description:
** myftp
*/

#include "myftp.h"

void cdup(char *command, client_t *client, server_t server)
{
    if (command)
        return send_message("xxx CDUP command does not take a parameter\r\n", client->socket);
    if (client->root_remoteness > 0) {
        client->root_remoteness -= 1;
        chdir("../");
        getcwd(client->directory, 4096);
        send_message(command_array[3].message, client->socket);
    } else
        return send_message("xxx You are already at the root\r\n", client->socket);
}