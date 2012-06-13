#include "client.h"

int connect_to_server (char* argv[])
{
  int sockfd = 0;
  struct sockaddr_in serv_addr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Error : Could not create socket \n");
    return 1;
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);

  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
  {
    printf("\n inet_pton error occured\n");
    return -1;
  }

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("\n Error : Connect Failed \n");
    return -1;
  }

  return sockfd;

}

int main(int argc, char* argv[])
{
  int s = -1;
  int choice = -1;

  if (argc != 2)
  {
    printf("\n Usage: %s <ip of server> \n",argv[0]);
    return 1;
  }

  if (((s = connect_to_server (argv))) == -1)
    return 1;

  printf("Client is connecting to platform... \n");

  while (1)
  {
    print_menu ();
    choice = get_choice ();

    switch (choice)
    {
      case 'a':
	handle_auto (s);
	break;
      case 'm':
	handle_manual (s);
      case 'q':
	printf("\nClient is disconnecting from platform... \n");
	close (s);
	return 0;
	break;
      default:
	fprintf(stderr, "Incorrect value...\n");
	break;
    }
  }

  return 0;
}

void write_cmd (int s, int cmd)
{
  char request[2];
  memset(&request, '0', sizeof(request));
  snprintf(request, 2, "%d", cmd);
  printf("this command is |%i|\n", cmd);
  printf("this messae is send to the server |%s|\n", request);
  write(s, request, MAX_LENGTH + 1);
}

void print_menu ()
{
  printf ("Menu client x86...\n");
  printf ("a : activation of the autonomous mode of the mobile platform\n");
  printf ("m : activation of the manual mode of the mobile platform\n");
  printf ("q : quit the program\n");
  printf ("Enter your choice : ");
}

/* get choice from stdin */
int get_choice ()
{
  char c;
  fgets(&c,2,stdin);
  return c;
}

void print_auto ()
{
  printf ("autonomous mode actived...\n");
  printf ("press q to quit this mode\n");

}

void handle_auto (int s)
{
  int mode_auto = 1;
  int choice = -1;

  write_cmd (s, AUTO);
  print_auto ();

  while (mode_auto)
  {
    choice = get_choice ();
    switch (choice)
    {
      case 'q' :
	mode_auto = 0;
	write_cmd (s, NONE);
	break;
      default:
	fprintf(stderr, "___Incorrect value...\n");
	break;
    }
  }
}

void print_manual ()
{
  printf ("manual mode actived...\n");
  printf ("press q to quit this mode\n");
  printf ("usage :\n");
  printf ("use z to go forward\n");
  printf ("use s to go backward\n");
  printf ("use a to rotate left\n");
  printf ("use e to rotate right\n");
  printf ("use x to stop\n");
}

void handle_manual (int s)
{
  int mode_manual = 1;
  int choice = -1;

  print_manual ();

  write_cmd (s, MANUAL);

  while (mode_manual)
  {
    choice = get_choice ();
    switch (choice)
    {
      case 'q' :
	mode_manual = 0;
	write_cmd (s, NONE);
	break;
      case 'z' :
	write_cmd (s, FORWARD);
	break;
      case 's' :
	write_cmd (s, BACKWARD);
	break;
      case 'a' :
	write_cmd (s, ROTATE_LEFT);
	break;
      case 'e' :
	write_cmd (s, ROTATE_RIGHT);
	break;
      case 'x' :
	write_cmd (s, STOP);
	break;
      default:
	fprintf(stderr, "%i is incorrect value...\n", choice);
	break;
    }
  }
}
