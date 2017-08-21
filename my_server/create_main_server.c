/*
** create_main_server.c for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Mon May  8 15:18:54 2017 Manu
** Last update Sun May 21 20:03:49 2017 Manu
*/

#include "../my_ftp.h"

int	close_err(pid_t pid, int client_fd)
{
  if (pid < 0)
    return (-1);
  else if (pid > 0 && pid != 0)
    close(client_fd);
}

int	serv_loop(int fd_sockt,
		  struct sockaddr_in sock_client)
{
  pid_t		pid;
  char*		client_ip;
  char		*str;
  int		client_fd;
  t_struct	my_struct;

  while (1)
    {
      if ((client_fd = accept(fd_sockt,
			      (struct sockaddr*) &sock_client,
			      &my_struct.size)) == -1)
	return (-1);
      if ((pid = fork()) == 0)
	{
	  close(fd_sockt);
	  client_ip = inet_ntoa(sock_client.sin_addr);
	  write(client_fd, "220 Prompt\r\n", strlen("220 Prompt\r\n"));
	  while ((str = get_next_line(client_fd)) != NULL)
	    call_funct(str, client_ip, client_fd, my_struct);
	  close(client_fd);
	  return (0);
	}
      close_err(pid, client_fd);
    }
  return (0);
}

int	create_sock(char *str)
{
  int			fd_sockt;
  struct protoent	*protoc;
  struct sockaddr_in	sock_ad;
  int			port;
  struct sockaddr_in	sock_client;
  socklen_t		size;

  size = sizeof(sock_client);
  port = atoi(str);
  sock_ad.sin_family = AF_INET;
  sock_ad.sin_port = htons(port);
  sock_ad.sin_addr.s_addr = INADDR_ANY;
  protoc = getprotobyname("TCP");
  if ((fd_sockt = socket(AF_INET, SOCK_STREAM, protoc->p_proto)) == -1)
    {
      printf("Cannot create socket\n");
      exit(0);
    }
  if ((bind(fd_sockt, (const struct sockaddr*)&sock_ad,
	    sizeof(sock_ad))) == -1)
    return (-1);
  listen(fd_sockt, 3);
  serv_loop(fd_sockt, sock_client);
  return (fd_sockt);
}
