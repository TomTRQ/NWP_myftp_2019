/*
** EPITECH PROJECT, 2020
** Main file
** File description:
** myftp
*/

#include "myftp.h"

bool print_help(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./myftp port path");
        return (true);
    } else if (argc == 2) {
        printf("Need 2 arguments as parameter\n");
        exit(84);
    }
    return (false);
}

int start_program(char **argv)
{
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 3)
        return (84);
    else if (print_help(argc, argv))
        return (0);
    else
        return (start_program(argv));
}