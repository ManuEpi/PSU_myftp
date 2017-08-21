##
## Makefile for  in /home/manu/TEK2/PSU_2016_myftp
## 
## Made by Manu
## Login   <vallen_e@epitech.net>
## 
## Started on  Mon May  8 15:18:18 2017 Manu
## Last update Sun May 21 15:10:17 2017 Manu
##

SRC		= my_server/create_main_server.c \
		  my_server/get_next.c \
		  my_server/basic.c \
		  my_server/main.c \
		  my_server/commands.c \
		  my_server/call_commands.c \
		  my_server/commands2.c \
		  my_server/commands3.c \
		  my_server/call_commands2.c

NAME		= server

CFLAGS  	= -c

CC		= cc

OBJ		= $(SRC:.c=.o)

all:		my_server

my_server:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
