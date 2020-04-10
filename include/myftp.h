/*
** EPITECH PROJECT, 2020
** myftp.h
** File description:
** myftp
*/

#ifndef MYFTP_
#define MYFTP_

#define MAX_CLIENTS 10
#define MAX_BUFFER 256
#define MAX_FOLDER_SIZE 4096
#define COMMAND_NUMBER 14
#define SOCKET_ERROR -1
#define ERROR 84
#define CORRECT 0

#include "struct.h"
#include "prototypes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#endif /* !MYFTP_ */
