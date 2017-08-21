/*
** call_commands.c for  in /home/manu/TEK2/PSU_2016_myftp/my_server
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Sat May 13 16:36:08 2017 Manu
** Last update Fri May 19 17:09:45 2017 Manu
*/

#include "../my_ftp.h"

void	call_funct4(char *str, char *client_ip, int client_fd,
		    t_struct *my_struct)
{
  if (strncmp(my_struct->command, "CWD", 3) == 0)
    {
      my_struct->cwd = strtok(NULL, " ");
      if (my_struct->is_pass == 1)
	cwd_funct(str, client_ip, client_fd, my_struct);
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  if (strncmp(my_struct->command, "DELE", 4) == 0)
    {
      my_struct->deleted = strtok(NULL, " ");
      if (my_struct->is_pass == 1)
	dele_funct(str, client_ip, client_fd, my_struct);
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  call_funct5(str, client_ip, client_fd, my_struct);
}

void	call_funct3(char *str, char *client_ip, int client_fd,
		    t_struct *my_struct)
{
  char	*tmp;

  if ((tmp = malloc(100)) == NULL)
    return ;
  if ((my_struct->my_pwd = malloc(100)) == NULL)
    return ;
  my_struct->my_pwd = getcwd(tmp, 1024);
  if (strncmp(my_struct->command, "PWD", 3) == 0)
    {
      if (my_struct->is_pass == 1)
	pwd_funct(str, client_ip, client_fd, my_struct);
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  if (strncmp(my_struct->command, "CDUP", 4) == 0)
    {
      if (my_struct->is_pass == 1)
	chdir("/");
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  call_funct4(str, client_ip, client_fd, my_struct);
}

void	call_funct2(char *str, char *client_ip, int client_fd,
		    t_struct *my_struct)
{
  if (strncmp(my_struct->command, "NOOP", 4) == 0)
    write(client_fd, "200 NOOP ok.\r\n", my_strlen("200 NOOP ok.\r\n"));
  else if (strncmp(str, "QUIT", 4) == 0)
    {
      if (my_struct->is_pass == 1)
	{
	  write(client_fd, "221 Goodbye.\r\n", my_strlen("221 Goodbye.\r\n"));
	  shutdown(client_fd, SHUT_RDWR);
	}
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  else if (strncmp(my_struct->command, "HELP", 4) == 0)
    help_funct(str, client_ip, client_fd, my_struct);
  call_funct3(str, client_ip, client_fd, my_struct);
}

int	call_funct(char *str, char *client_ip,
		   int client_fd, t_struct *my_struct)
{
  my_struct->command = strdup(strtok(str, " "));
  if (strncmp(my_struct->command, "USER", 4) == 0)
    {
      my_struct->username = strtok(NULL, " ");
      if (my_struct->username == NULL)
	write(client_fd, "530 Permission denied.\r\n", 24);
      else if (my_struct->username != NULL)
	user_funct(str, client_ip, client_fd, my_struct);
    }
  else if (strncmp(my_struct->command, "PASS", 4) == 0)
    pass_funct(str, client_ip, client_fd, my_struct);
  else if (strncmp(my_struct->command, "PASV", 4) == 0)
    {
      if (my_struct->is_pass == 1)
	{
	  pasv_funct(str, client_ip, client_fd);
	  my_struct->pasv_act = 1;
	}
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  else
    check_command(str, client_ip, client_fd, my_struct);
  call_funct2(str, client_ip, client_fd, my_struct);
}

void	check_command(char *str, char *client_ip,
		      int client_fd, t_struct *my_struct)
{
  if (strncmp(my_struct->command, "NOOP", 4) != 0 &&
      strncmp(my_struct->command, "QUIT", 4) != 0 &&
      strncmp(my_struct->command, "HELP", 4) != 0 &&
      strncmp(my_struct->command, "PWD", 3) != 0 &&
      strncmp(my_struct->command, "CWD", 3) != 0 &&
      strncmp(my_struct->command, "CDUP", 4) != 0 &&
      strncmp(my_struct->command, "DELE", 4) != 0 &&
      strncmp(my_struct->command, "PORT", 4) != 0 &&
      strncmp(my_struct->command, "LIST", 4) != 0)
    check_found(str, client_ip, client_fd, my_struct);
}
