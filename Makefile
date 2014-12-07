##
## Makefile for 102chiffrement in /home/david_h/rendu/102chiffrement
## 
## Made by Sullivan David
## Login   <david_h@epitech.net>
## 
## Started on  Fri Nov 21 15:10:41 2014 david_h
## Last update Sun Dec  7 16:32:49 2014 David Sullivan
##

NAME	= 102chiffrement

LIB	= ./libmy/libmy.a

SRC	= main.c \
	  create_matrice.c \
	  mult_matrice.c \
	  crypt.c \
	  decrypt.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	cd libmy/lib; make re
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
