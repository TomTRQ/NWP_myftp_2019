/*
** EPITECH PROJECT, 2020
** port.c
** File description:
** myftp
*/

#include "myftp.h"

void port(char *port, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("530 Need connection\r\n", client->socket));
    if (!port || my_check_nbr(port) == 0)
        return (send_message("501 PORT command needs a valid \
port as parameter.\r\n", client->socket));
    send_message(command_array[8].message, client->socket);
    client->is_passive = false;
}