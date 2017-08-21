/*
** call_commands2.c for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Wed May 17 23:00:33 2017 Manu
** Last update Sun May 21 15:00:17 2017 Manu
*/

#include "../my_ftp.h"

void    call_funct6(char *str, char *client_ip, int client_fd,
                    t_struct *my_struct)
{
  if (strncmp(my_struct->command, "RETR", 4) == 0)
    {
      if (my_struct->is_pass == 1)
	{
	  if (my_struct->pasv_act == 1)
	    retr_funct();
	  else
	    write(client_fd, "425 Use PORT or PASV first.\r\n",
		  strlen("425 Use PORT or PASV first.\r\n"));
	}
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
}

void    call_funct5(char *str, char *client_ip, int client_fd,
                    t_struct *my_struct)
{
  DIR	*dir;
  struct dirent	*rent;
  const char	*pwd;
  char		*tmp;

  if ((tmp = malloc(100)) == NULL)
    return ;
  if ((pwd = malloc(100)) == NULL)
    return ;
  pwd = getcwd(tmp, 1024);
  dir = opendir(pwd);
  if (strncmp(my_struct->command, "LIST", 4) == 0)
    {
      if (my_struct->is_pass == 1)
	{
	  if (my_struct->pasv_act == 1)
	    list_funct(dir, client_fd, rent);
	  else
	    write(client_fd, "425 .\r\n", strlen("425 .\r\n"));
	}
      else
	write(client_fd, "530 Please login with USER and PASS.\r\n",
	      my_strlen("530 Please login with USER and PASS.\r\n"));
    }
  call_funct6(str, client_ip, client_fd, my_struct);
}
