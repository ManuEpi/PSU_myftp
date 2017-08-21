/*
** commands.c for  in /home/manu/TEK2/PSU_2016_myftp/my_server
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Sat May 13 16:36:42 2017 Manu
** Last update Sun May 21 20:03:25 2017 Manu
*/

#include "../my_ftp.h"

void    help_funct(char *str, char *client_ip,
		   int client_fd, t_struct *my_struct)
{
  if (my_struct->is_pass == 1)
    {
      write(client_fd, "214-The following commands are recognized.\r\n",
            my_strlen("214-The following commands are recognized.\r\n"));
      write(client_fd, " ABOR ACCT ALLO APPE CDUP CWD DELE EPRT EPSV FEAT ",
            my_strlen(" ABOR ACCT ALLO APPE CDUP CWD DELE EPRT EPSV FEAT "));
      write(client_fd, "HELP LIST MDTM MKD\r\n",
	    my_strlen("HELP LIST MDTM MKD\r\n"));
      write(client_fd, " MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN ",
            my_strlen(" MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN "));
      write(client_fd, "REST RETR RMD  RNFR\r\n",
	    my_strlen("REST RETR RMD  RNFR\r\n"));
      write(client_fd, " RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST TYPE ",
            my_strlen(" RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST TYPE "));
      write(client_fd, "USER XCUP XCWD XMKD\r\n XPWD XRMD\n",
            my_strlen("USER XCUP XCWD XMKD\r\n XPWD XRMD\n"));
      write(client_fd, "214 Help OK.\r\n", my_strlen("214 Help OK.\r\n"));
    }
  else
    write(client_fd, "530 Please login with USER and PASS.\r\n",
          my_strlen("530 Please login with USER and PASS.\r\n"));
}

void    user_funct(char *str, char *client_ip, int client_fd,
		   t_struct *my_struct)
{
  if (strncmp(my_struct->username, "Anonymous", 9) == 0)
    my_struct->anonym = 1;
  write(client_fd, "331 Please specify a password.\r\n",
	my_strlen("331 Please specify a password.\r\n"));
}

void    pass_funct(char *str, char *client_ip,
		   int client_fd, t_struct *my_struct)
{
  if (my_struct->username != NULL)
    {
      if (my_struct->anonym == 1)
      	{
      write(client_fd, "230 Login successful.\r\n",
	    my_strlen("230 Login successful.\r\n"));
      my_struct->is_pass = 1;
      my_struct->anonym = 0;
	}
      else
	write(client_fd, "530 Login incorrect.\r\n",
	      my_strlen("530 Login incorrect.\r\n"));
    }
  else
    write(client_fd, "503 Login with USER first.\r\n",
          my_strlen("503 Login with USER first.\r\n"));
}

int    pasv_funct(char *str, char *client_ip, int client_fd)
{
  t_struct      my_struct;

  if ((my_struct.buf = malloc(500)) == NULL)
    printf("Can't alloc\n");
  my_struct.port2 = rand()%255 + 1;
  my_struct.size = sizeof(my_struct.sock_data_client);
  my_struct.sock_data.sin_family = AF_INET;
  my_struct.sock_data.sin_port = htons(255 * 256 + my_struct.port2);
  my_struct.sock_data.sin_addr.s_addr = INADDR_ANY;
  my_struct.data_sockt = socket(AF_INET, SOCK_STREAM, 0);
  if (bind(my_struct.data_sockt, (const struct sockaddr*)&my_struct.sock_data,
	   sizeof(my_struct.sock_data)) == -1)
    return (0);
  if (listen(my_struct.data_sockt, 100) == -1)
    return (0);
  sprintf(my_struct.buf, "227 Entering Passive Mode (%s,255,%d)\r\n",
          epur_str(client_ip), my_struct.port2);
  write(client_fd, my_struct.buf, my_strlen(my_struct.buf));
  if ((my_struct.data_client = accept(my_struct.data_sockt, (struct sockaddr*)
				      &my_struct.sock_data_client,
				      &my_struct.size)) == -1)
    return (0);
}

void    check_found(char *str, char *client_ip,
		    int client_fd, t_struct *my_struct)
{
  if (my_struct->is_pass == 1)
    write(client_fd, "500 Unknown command.\r\n",
	  my_strlen("500 Unknown command.\r\n"));
  else
    write(client_fd, "530 Please login with USER and PASS.\r\n",
	  my_strlen("530 Please login with USER and PASS.\r\n"));
}
