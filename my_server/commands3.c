/*
** commands3.c for  in /home/manu/TEK2/PSU_2016_myftp/my_server
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Wed May 17 17:53:43 2017 Manu
** Last update Sun May 21 15:09:37 2017 Manu
*/

#include "../my_ftp.h"

void	list_funct(DIR * dir, int client_fd,
		   struct dirent *rent)
{
  t_struct	*my_struct;

  if (dir != NULL)
    {
      write(client_fd, "150 Here comes the directory listing.\r\n",
	    strlen("150 Here comes the directory listing.\r\n"));
      write(client_fd, "226 Directory send OK.\r\n",
	    strlen("226 Directory send OK.\r\n"));
      while (rent = readdir(dir))
	{
	  write(client_fd, rent->d_name,
	  	strlen(rent->d_name));
	  write(client_fd, "\r\n", 2);
	}
    }
  else
    perror ("Couldn't open the directory");
  (void)closedir(dir);
}

int	retr_funct()
{
  return (0);
}
