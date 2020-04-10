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
    DIR* dir;

    if (argc == 3) {
        dir = opendir(argv[2]);
        if (ENOENT == errno) {
            printf("Wrong directory entered\n");
            return (true);
        }
        if (my_check_nbr(argv[1]) == 0) {
            printf("The first argument is not a positive integer\n");
            return (true);
        }
        closedir(dir);
    }
    return (false);
}

int main(int argc, char **argv)
{
    int server_socket = 0;

    if (argc == 1 || argc > 3 || is_wrong_parameters(argc, argv))
        return (ERROR);
    else if (print_help(argc, argv))
        return (CORRECT);
    server_socket = create_server(argv);
    if (server_socket == SOCKET_ERROR)
        return (ERROR);
    if (server_loop(server_socket, atoi(argv[1]), argv[2]) == SOCKET_ERROR) {
        close(server_socket);
        return (ERROR);
    }
    return (CORRECT);
}