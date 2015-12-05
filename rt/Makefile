##
## Makefile for raytracer in /home/simon_o//raytracer-2017-simon_o
##
## Made by antoine simon
## Login   <simon_o@epitech.net>
##
## Started on  Mon Apr 29 09:02:14 2013 antoine simon
## Last update Tue Apr 30 09:12:23 2013 antoine simon
##

NAME	= rt

SRC	= main.c \
	atof.c \
	parsing.c \
	strtoll.c \
	inter.c \
	calc_all.c \
	my_putstr.c \
	resolver.c \
	get_next_line.c \
	tools.c \
	type/type.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) -lmlx -lXext -lX11 -lm

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all