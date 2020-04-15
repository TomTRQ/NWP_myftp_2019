/*
** EPITECH PROJECT, 2020
** dele.c
** File description:
** myftp
*/

#include "myftp.h"
#include <fcntl.h>

void dele(char *file, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("530 Need connection\r\n", client->socket));
    if (!file)
        return (send_message("501 DELE takes a file as \
parameter\r\n", client->socket));
    if (open(file, O_RDONLY) == -1)
        return (send_message("550 file not found\r\n", client->socket));
    if (remove(file) == 0)
        send_message(command_array[5].message, client->socket);
    else
        send_message("500 An error occured with the DELE \
command\r\n", client->socket);
}