/*
** EPITECH PROJECT, 2020
** create_server.c
** File description:
** myftp
*/

#include "myftp.h"

int create_server(char **argv)
{
    struct sockaddr_in sin;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t len_sin = sizeof(sin);

    if (server_socket < 0)
        return (SOCKET_ERROR);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(argv[1]));
    if (bind(server_socket, (struct sockaddr*)&sin, len_sin) < 0)
        return (SOCKET_ERROR);
    listen(server_socket, MAX_CLIENTS);
    return (server_socket);
}