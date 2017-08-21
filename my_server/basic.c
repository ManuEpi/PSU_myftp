/*
** basic.c for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Thu May 11 23:26:23 2017 Manu
** Last update Sun May 21 15:17:15 2017 Manu
*/

#include "../my_ftp.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i += 1;
    }
}

char	*epur_str(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.')
        str[i] = ',';
      i += 1;
    }
  return (str);
}

void	epur_str2(char *str)
{
  char	sep;
  int	i;

  sep = -1;
  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  if (sep == 1)
	    my_putchar(' ');
	  sep = 0;
	  my_putchar(str[i]);
	}
      else if (sep == 0)
	sep = 1;
      i += 1;
    }
}
