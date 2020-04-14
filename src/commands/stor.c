/*
** EPITECH PROJECT, 2020
** stor.c
** File description:
** myftp
*/

#include "myftp.h"
#include <fcntl.h>

void stor(char *commands, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("530 Need account for \
        storing files\r\n", client->socket));
    if (!commands)
        return (send_message("501 STOR takes a pathname \
        as parameter\r\n", client->socket));
    if (open(commands, O_RDONLY) == -1)
        return (send_message("550 file not found\r\n", client->socket));
    send_message(command_array[12].message, client->socket);
}