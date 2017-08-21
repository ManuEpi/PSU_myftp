/*
** my_ftp.h for  in /home/manu/TEK2/PSU_2016_myftp
** 
** Made by Manu
** Login   <vallen_e@epitech.net>
** 
** Started on  Mon May  8 15:18:29 2017 Manu
** Last update Sun May 21 15:52:55 2017 Manu
*/

#ifndef MY_FTP_H_
# define MY_FTP_H_

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_S 1

typedef struct		s_struct
{
  int			data_sockt;
  int			data_client;
  int			port2;
  socklen_t		size;
  char			*buf;
  struct protoent	*protocl;
  struct sockaddr_in	sock_data;
  struct sockaddr_in	sock_data_client;
  char			*command;
  char			*username;
  int			pasv_act;
  char			*cwd;
  char			*my_pwd;
  char			*deleted;
  int			anonym;
  int			is_pass;
}			t_struct;

void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(char *str);
char	*my_realloc(char *str);
char	*get_next_line(int fd);
char	*epur_str(char *str);
void	my_put_nbr(int nb);
void    check_found(char *str, char *client_ip,
		    int client_fd, t_struct *my_struct);
void    check_command(char *str, char *client_ip,
		      int client_fd, t_struct *my_struct);
void    user_funct(char *str, char *client_ip, int client_fd,
		   t_struct *my_struct);
void    pwd_funct(char *str, char *client_ip, int client_fd,
		  t_struct *my_struct);
void    cwd_funct(char *str, char *client_ip, int client_fd,
		  t_struct *my_struct);
void    list_funct(DIR *dir, int client_fd, struct dirent *rent);
void    dele_funct(char *str, char *client_ip, int client_fd,
		  t_struct *my_struct);
void    pass_funct(char *str, char *client_ip,
		   int client_fd, t_struct *my_struct);
void    help_funct(char *str, char *client_ip,
		   int client_fd, t_struct *my_struct);
int	pasv_funct(char *str, char *client_ip, int client_fd);
int     serv_loop(int fd_sockt, struct sockaddr_in sock_client);
int	create_sock(char *str);
int	create_sock_client(char *str, char *str2);

#endif
