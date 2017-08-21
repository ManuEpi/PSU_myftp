/*
** get_next.c for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Thu May 11 17:02:39 2017 Manu
** Last update Sun May 21 15:20:00 2017 Manu
*/

#include "../my_ftp.h"

char	*my_realloc(char *str)
{
  char	*str2;
  int	i;

  i = 0;
  if ((str2 = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    printf("Can't alloc\n");
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i += 1;
    }
  str2[i + 1] = '\0';
  free(str);
  return (str2);
}

char*	get_next_line(int fd)
{
  int	i;
  int	lengt;
  char	buf[BUFF_S];
  char	*str;

  i = 0;
  lengt = 0;
  if ((str = malloc(sizeof(char))) == NULL)
    printf("Can't alloc\n");
  str[0] = '\0';
  while ((lengt = read(fd, buf, BUFF_S)) > 0 && buf[0] != '\n')
    {
      str = my_realloc(str);
      str[i] = buf[0];
      i += 1;
    }
  if (lengt == 0 && i == 0)
    return (NULL);
  else
    return (str);
}
