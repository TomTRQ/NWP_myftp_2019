/*
** EPITECH PROJECT, 2020
** Main file
** File description:
** myftp
*/

#include "myftp.h"

#include <dirent.h>
#include <errno.h>

int my_char_isnum(char c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}

int my_check_nbr(char *str)
{
    int a = 0;

    if (str[a] == '-')
        a++;
    while (str[a] != '\0') {
        if (my_char_isnum(str[a]) == 0)
            return (0);
        a++;
    }
    return (1);
}

bool is_wrong_parameters(int argc, char **argv)
{
    DIR* dir = opendir(argv[2]);

    if (argc == 3) {
        if (ENOENT == errno) {
            printf("Wrong directory entered\n");
            return (true);
        }
        if (my_check_nbr(argv[1]) == 0) {
            printf("The first argument is not a positive integer\n");
            return (true);
        }
    }
    closedir(dir);
    return (false);
}

bool print_help(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport\tis the port number on which the server socket listens\n");
        printf("\tpath\tis thr path to the home directory for the Anonymous user\n");
        return (true);
    } else if (argc == 2) {
        printf("Need 2 arguments as parameter\n");
        exit(ERROR);
    }
    return (false);
}

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

void send_message(char *message, int dest)
{
    int size = strlen(message);

    write(dest, message, size);
}

char *get_message(int from)
{
    char *test = malloc(MAX_BUFFER);

    if (test == NULL)
        return (NULL);
    read(from, test, MAX_BUFFER);
    return (test);
}

void call_command(char *line, client_t *client)
{
    char **array = my_str_to_word_array(line);

    if (array == NULL || array[0] == NULL)
        return;
    for (int i = 0; i < COMMAND_NUMBER; i++)
        if (strcmp(array[0], command_array[i].name) == 0) {
            command_array[i].func(array[1], client);
            free(line);
            return;
        }
    free(line);
    send_message("xxx Wrong command\r\n", client->socket);
}

void add_client(int csock, client_t *clients[])
{
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL)
        return;
    new_client->socket = csock;
    new_client->directory = ".";
    new_client->username = NULL;
    new_client->passwd = false;
    new_client->is_connected = false;
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (clients[i] == NULL) {
            clients[i] = new_client;
            return;
        }
}

int wait_for_client(int server_socket, int port, char *folder_path)
{
    int csock = 0;
    struct sockaddr_in cin;
    socklen_t len_cin = sizeof(cin);
    client_t **clients = calloc(sizeof(client_t *) * MAX_CLIENTS, MAX_CLIENTS);
    fd_set readfds;

    if (clients == NULL)
        return (SOCKET_ERROR);
    printf("Waiting for clients on port %d...\n", port);
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_socket, &readfds);
        if (select(FD_SETSIZE, &readfds , NULL , NULL , NULL) < 0)
            return (SOCKET_ERROR);
        csock = accept(server_socket, (struct sockaddr *)&cin, &len_cin);
        printf("New connection from ip: %s, port: %d\n", inet_ntoa(cin.sin_addr), ntohs(cin.sin_port));
        if (FD_ISSET(server_socket, &readfds)) {
            send_message("220 Connection established\r\n", csock);
            add_client(csock, clients);
            while (1)
                call_command(get_message(csock), clients[0]);
        }
    }
    close(server_socket);
    return (CORRECT);
}

int main(int argc, char **argv)
{
    int server_socket = 0;

    if (argc == 1 || argc > 3 || is_wrong_parameters(argc, argv))
        return (ERROR);
    else if (print_help(argc, argv))
        return (CORRECT);
    server_socket = create_server(argv);
    if (server_socket == SOCKET_ERROR || wait_for_client(server_socket, atoi(argv[1]), argv[2]) == SOCKET_ERROR)
        return (ERROR);
}