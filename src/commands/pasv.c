/*
** EPITECH PROJECT, 2020
** pasv.c
** File description:
** myftp
*/

#include "myftp.h"

char *string_to_send(int first_port, int second_port)
{
    char *to_send = calloc(39, 39);
    char port[12];

    if (!to_send)
        return ("500 An error occured with the PASV command\r\n");
    strcpy(to_send, "227 Entering Passive Mode (127,0,0,1,");
    sprintf(port, "%d", first_port);
    strcat(to_send, port);
    strcat(to_send, ",");
    sprintf(port, "%d", second_port);
    strcat(to_send, port);
    strcat(to_send, ")\r\n");
    return (to_send);
}

bool is_pasv_error(client_t *client, char *first_argument, int data_socket)
{
    if (!client->is_connected) {
        send_message("530 Need connection\r\n", client->socket);
        return (true);
    }
    if (first_argument) {
        send_message("501 PASV command has no \
parameter\r\n", client->socket);
        return (true);
    }
    if (data_socket < 0) {
        send_message("500 Error with creating \
the data socket\r\n", client->socket);
        return (true);
    }
    return (false);
}

void find_port_to_bind(int data_socket, int *first_port, int *second_port)
{
    struct sockaddr_in sin;
    socklen_t len_sin = sizeof(sin);

    if (*second_port < 255)
        *second_port += 1;
    else if (*first_port < 255)
        *first_port += 1;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(*first_port * 256 + *second_port);
    if (bind(data_socket, (struct sockaddr*)&sin, len_sin) < 0)
        find_port_to_bind(data_socket, first_port, second_port);
}

void pasv(char *first_argument, client_t *client, server_t server)
{
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    int first_port = 5;
    int second_port = 4;

    if (data_socket < 0)
        return (send_message("500 Error with PASV\r\n", client->socket));
    if (is_pasv_error(client, first_argument, data_socket))
        return;
    find_port_to_bind(data_socket, &first_port, &second_port);
    send_message(string_to_send(first_port, second_port), client->socket);
    client->data_port = first_port * 256 + second_port;
    client->is_passive = true;
    client->data_socket = data_socket;
}