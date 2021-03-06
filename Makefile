##
## Makefile for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
##
## Made by Mathieu Sauvau
## Login   <sauvau_m@epitech.net>
##
## Started on  Mon Nov 30 09:56:55 2015 Mathieu Sauvau
## Last update Wed Dec  9 15:03:03 2015 Mathieu Sauvau
##

CFLAGS += -W -Wall -Wextra -Werror
CFLAGS += -I./include/

NAME = my_select

SRC = my_select.c \
      my_putchar.c \
      my_putstr.c \
      my_strlen.c \
      list_utility.c \
      list_utility2.c \
      key.c \
      move.c \
      select_utility.c \
      my_strcmp.c \
      my_strncmp.c \
      init_term.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME) -lncurses

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
