/*
** EPITECH PROJECT, 2020
** Main file
** File description:
** myftp
*/

#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include "myftp.h"

//nc -C 127.0.0.1 4242

bool is_wrong_parameters(int argc, char **argv)
{
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

int start_program(char **argv)
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
    listen(server_socket, 10);
    return (server_socket);
}

int wait_for_client(int server_socket, int port)
{
    int csock = 0;
    struct sockaddr_in cin;
    pid_t child_pid = 0;
    socklen_t len_cin = sizeof(cin);

    printf("En attente qu'un client se connecte sur le port %d...\n", port);
    while (1) {
        csock = accept(server_socket, (struct sockaddr*)&cin, &len_cin);
        if (csock < 0)
            return (SOCKET_ERROR);
        child_pid = fork();
        if (child_pid == 0) {
            printf("Un client se connecte de %s:%d\n\n", inet_ntoa(cin.sin_addr), htons(cin.sin_port));
            sleep(5);
            write(csock, "Hello world!!\n", 16);
            kill(getpid(), SIGKILL);
        }
        close(csock);
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
    server_socket = start_program(argv);
    if (server_socket == SOCKET_ERROR || wait_for_client(server_socket, atoi(argv[1])) == SOCKET_ERROR)
        return (ERROR);
}