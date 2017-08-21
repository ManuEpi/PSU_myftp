/*
** commands2.c for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Sat May 13 17:21:30 2017 Manu
** Last update Fri May 19 17:11:57 2017 Manu
*/

#include "../my_ftp.h"

void    pwd_funct(char *str, char *client_ip, int client_fd,
		  t_struct *my_struct)
{
  write(client_fd, "257 ", 4);
  write(client_fd, "\"", 1);
  write(client_fd, my_struct->my_pwd,
	my_strlen(my_struct->my_pwd));
  write(client_fd, "\"", 1);
  write(client_fd, "\r\n", 2);
}

void    cwd_funct(char *str, char *client_ip, int client_fd,
		  t_struct *my_struct)
{
  if (my_struct->cwd == NULL)
    write(client_fd, "550 Failed to change directory.\r\n",
	  my_strlen("550 Failed to change directory.\r\n"));
  else
    {
      if (chdir(my_struct->cwd) == -1)
	write(client_fd, "550 Failed to change directory.\r\n",
	      my_strlen("550 Failed to change directory.\r\n"));
      else
	write(client_fd, "250 Directory successfully changed.\r\n",
	      my_strlen("250 Directory successfully changed.\r\n"));
    }
  return ;
}
void    dele_funct(char *str, char *client_ip, int client_fd,
		  t_struct *my_struct)
{
  if (my_struct->deleted == NULL)
    write(client_fd, "550 Failed to delete this file.\r\n",
	  my_strlen("550 Failed to delete this file.\r\n"));
  else
    {
      if (remove(my_struct->deleted) == -1)
	write(client_fd, "550 Failed to delete this file.\r\n",
	      my_strlen("550 Failed to delete this file.\r\n"));
      else
	write(client_fd, "250 Requested file action okay, completed.\r\n",
	      my_strlen("250 Requested file action okay, completed.\r\n"));
    }
  return ;
}
