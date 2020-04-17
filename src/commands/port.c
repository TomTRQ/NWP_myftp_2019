/*
** EPITECH PROJECT, 2020
** port.c
** File description:
** myftp
*/

#include "myftp.h"

bool generate_new_socket(char *port, client_t *client)
{
    struct sockaddr_in sin;
    socklen_t len_sin = sizeof(sin);
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (data_socket < 0) {
        send_message("500 Error with PORT\r\n", client->socket);
        return (false);
    }
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(port));
    if (bind(data_socket, (struct sockaddr*)&sin, len_sin) < 0) {
        send_message("500 Error with PORT\r\n", client->socket);
        return (false);
    }
    listen(data_socket, 1);
    client->is_passive = false;
    client->data_socket = data_socket;
    return (true);
}

void port(char *port, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("530 Need connection\r\n", client->socket));
    if (!port || my_check_nbr(port) == 0)
        return (send_message("501 PORT command needs a valid \
port as parameter.\r\n", client->socket));
    if (!generate_new_socket(port, client))
        return;
    send_message(command_array[8].message, client->socket);
}