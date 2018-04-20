##
## Makefile for Makefile in /home/founauser/My_FTL
## 
## Made by Founa Ben Chaabane
## Login   <bencha_f@etna-alternance.net>
## 
## Started on  Mon Apr  9 11:15:00 2018 Founa Ben Chaabane
## Last update Sat Apr 14 10:49:43 2018 Founa Ben Chaabane
##

CC      =       gcc

NAME    =       my_ftl

SRC     =       main.c  \
                my_getnbr.c     \
		my_string.c     \
                my_put_nbr.c	\
		readline.c	\
		air_shed.c	\
		my_free.c	\
		container.c	\
		system_control.c	\
		system_repair.c	\
		enemy.c	\
		my_random.c	\
		lose.c	\
		attack.c	\
		jump.c	\
		stat.c	\
		detect.c	\
		game_loop.c	\
		win.c		\
		sheat.c

OBJ     =       $(SRC:%.c=%.o)

RM      =       rm      -r      -f

CFLAGS  =       -W -Werror -Wall -g3

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

temp:
	rm	-f	*~

.PHONY  =	clean	fclean	re	all	temp
