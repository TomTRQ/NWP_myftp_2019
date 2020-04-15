/*
** EPITECH PROJECT, 2020
** prototypes.c
** File description:
** myftp
*/

#ifndef PROTOTYPES_
#define PROTOTYPES_

#include "struct.h"

char *get_message(int from);
int my_check_nbr(char *str);
int create_server(char **argv);
bool print_help(int argc, char **argv);
client_t *remove_client(client_t *client);
void send_message(char *message, int dest);
void send_message(char *message, int dest);
char **my_str_to_word_array(char const *str);
int server_loop(int server_socket, int port, char *folder_path);
char *get_actual_relative_directory(char *full_path, char *root);
char **concatenate_commands(char *previous_command, char *actual_command);
void new_client(client_t *clients[], int server_socket, \
char *folder_path, int *fd_max);
void reset_after_command(int root_remoteness, char **array, \
char *line, client_t *client);

void cdup(char *, client_t *, server_t);
void cwd(char *, client_t *, server_t);
void dele(char *, client_t *, server_t);
void help(char *, client_t *, server_t);
void list(char *, client_t *, server_t);
void noop(char *, client_t *, server_t);
void pass(char *, client_t *, server_t);
void pasv(char *, client_t *, server_t);
void port(char *, client_t *, server_t);
void pwd(char *, client_t *, server_t);
void quit(char *, client_t *, server_t);
void retr(char *, client_t *, server_t);
void stor(char *, client_t *, server_t);
void user(char *, client_t *, server_t);

static command_t command_array[] = {
    {"USER", "331 User name okay, need password.\r\n", &user, 331},
    {"PASS", "332 Need account for login.\r\n", &pass, 332},
    {"CWD", "250 Directory successfully changed.\r\n", &cwd, 250},
    {"CDUP", "200 Directory successfully changed.\r\n", &cdup, 200},
    {"QUIT", "221 Closing connection to the server.\r\n", &quit, 221},
    {"DELE", "250 Requested file action okay, completed.\r\n", &dele, 250},
    {"PWD", "257 Actual directory: \"DIRECTORY\".\r\n", &pwd, 257},
    {"PASV", "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n", &pasv, 227},
    {"PORT", "200 Command okay.\r\n", &port, 200},
    {"HELP", "214 Help message. HELP may take an argument to \
print informations about commands\r\n", &help, 214},
    {"NOOP", "200 Command okay.\r\n", &noop, 200},
    {"RETR", "150 File status okay; \
about to open data connection.\r\n", &retr, 150},
    {"STOR", "150 File status okay; \
about to open data connection.\r\n", &stor, 150},
    {"LIST", "150 File status okay; \
about to open data connection.\r\n", &list, 150}
};

static char *help_array[] = {
    "214 Specity user for authentification\r\n",
    "214 Specity password for authentication\r\n",
    "214 Change working directory\r\n",
    "214 Change working directory to parent directory\r\n",
    "214 Disconnection\r\n",
    "214 Delete file on the server\r\n",
    "214 Print working directory\r\n",
    "214 Enable \"passive\" mode for data transfer\r\n",
    "214 Enable \"active\" mode for data transfer\r\n",
    "214 List available commands\r\n",
    "214 Do nothing\r\n",
    "214 Download file from server to client\r\n",
    "214 Upload file from client to server\r\n",
    "214 List files in the current working directory\r\n"
};


#endif /* !PROTOTYPES_ */
