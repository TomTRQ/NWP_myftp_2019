/*
** EPITECH PROJECT, 2020
** print_help.c
** File description:
** myftp
*/

#include "myftp.h"

bool print_help(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport\tis the port number on which \
        the server socket listens\n");
        printf("\tpath\tis thr path to the home directory \
        for the Anonymous user\n");
        return (true);
    } else if (argc == 2) {
        printf("Need 2 arguments as parameter\n");
        exit(ERROR);
    }
    return (false);
}