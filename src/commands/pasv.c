/*
** EPITECH PROJECT, 2020
** pasv.c
** File description:
** myftp
*/

#include "myftp.h"

char *string_to_send()
{
    char *to_send = calloc(39, 39);

    if (!to_send)
        return ("xxx An error occured with the PASV command\r\n");
    strcpy(to_send, "227 Entering Passive Mode (127,0,0,1, ");

    strcpy(to_send, ")\r\n");
}

void pasv(char *first_argument, client_t *client, server_t server)
{
    struct sockaddr_in sin;
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t len_sin = sizeof(sin);

    if (first_argument)
        return send_message("xxx PASV command has no parameter\r\n", client->socket);
    if (data_socket < 0)
        return send_message("xxx Error with creating the data socket", client->socket);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    if (bind(data_socket, (struct sockaddr*)&sin, len_sin) < 0)
        return send_message("xxx Error with binding the data socket", client->socket);
    client->is_passive = true;
    send_message(string_to_send(), client->socket);
}