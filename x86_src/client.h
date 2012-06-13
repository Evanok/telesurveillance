/**
**

** \file client.h
** \brief define client header file
** \author ArthurLAMBERT
** \date 07/05/2012
**
**/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1

enum cmd
{
  AUTO,
  MANUAL,
  NONE,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  ROTATE_LEFT,
  ROTATE_RIGHT,
  STOP,
  QUIT
};

int connect_to_server (char* argv[]);
void write_cmd (int s, int cmd);
void print_menu ();
int get_choice ();
void print_auto ();
void handle_auto (int s);
void print_manual ();
void handle_manual (int s);

#endif /* !CLIENT_H_ */
