/*
** main.c for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Thu May 11 23:27:20 2017 Manu
** Last update Mon May 22 14:22:35 2017 Manu
*/

#include "../my_ftp.h"

int    path_arg(char *path)
{
  if (open(path, O_DIRECTORY) == -1)
    {
      if (mkdir(path, 0700) == -1)
	return (-1);
      return (-1);
    }
  return (0);
}

int     main(int ac, char **av)
{
  int   sockt;

  srand(time(NULL));
  if (ac != 3)
    {
      printf("Usage : ./server port path\n");
      exit(0);
    }
  create_sock(av[1]);
  path_arg(av[2]);
  return (0);
}
