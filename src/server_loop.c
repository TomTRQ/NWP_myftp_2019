/*
** EPITECH PROJECT, 2020
** server_loop
** File description:
** myftp
*/

#include "myftp.h"

void reset_after_command(int root_remoteness, char **array, char *line)
{
    for (int i = 0; i < root_remoteness; i++)
        chdir("../");
    free(line);
    if (array[1])
        free(array[1]);
    free(array[0]);
    free(array);
}

void call_command(char *line, client_t *client, server_t server)
{
    char **command = my_str_to_word_array(line);
    int temp_remoteness = client->root_remoteness;

    if (command == NULL || command[0] == NULL)
        return;
    chdir(client->directory);
    printf("COMMAND: %s\n", command[0]);
    for (int i = 0; i < COMMAND_NUMBER; i++)
        if (strcmp(command[0], command_array[i].name) == 0) {
            command_array[i].func(command[1], client, server);
            return reset_after_command(temp_remoteness, command, line);
        }
    reset_after_command(temp_remoteness, command, line);
    send_message("xxx Wrong command\r\n", client->socket);
}

client_t *remove_client(client_t *client)
{
    free(client->username);
    free(client->directory);
    free(client);
    return (NULL);
}

void update_server(int server_socket, client_t **clients, fd_set *readfds, fd_set *writefds)
{
    FD_ZERO(readfds);
    FD_ZERO(writefds);
    FD_SET(server_socket, readfds);
    FD_SET(server_socket, writefds);
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (clients[i] && clients[i]->is_set == false)
            clients[i] = remove_client(clients[i]);
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (clients[i]) {
            FD_SET(clients[i]->socket, readfds);
            FD_SET(clients[i]->socket, writefds);
        }
}

int server_loop(int server_socket, int port, char *folder_path)
{
    client_t **clients = calloc(sizeof(client_t *) * MAX_CLIENTS, MAX_CLIENTS);
    server_t server;
    fd_set readfds;
    fd_set writefds;
    int fd_max = server_socket + 3;

    if (clients == NULL)
        return (SOCKET_ERROR);
    server.port = port;
    server.directory = folder_path;
    printf("Waiting for clients on port %d...\n", port);
    while (1) {
        update_server(server_socket, clients, &readfds, &writefds);
        if (select(fd_max, &readfds, &writefds, NULL , NULL) < 0)
            return (SOCKET_ERROR);
        if (FD_ISSET(server_socket, &readfds)) {
            new_client(clients, server_socket, folder_path);
            fd_max += 1;
        }
        for (int i = 0; i < MAX_CLIENTS; i++)
            if (clients[i] && FD_ISSET(clients[i]->socket, &readfds))
                call_command(get_message(clients[i]->socket), clients[i], server);
    }
    return (CORRECT);
}