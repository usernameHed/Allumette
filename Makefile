##
## Makefile for  in /home/belfio_u/rendu/EXOTEST/FDF
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Mon Oct 27 15:13:44 2014 ugo belfiore
## Last update Thu Feb 12 21:26:20 2015 ugo belfiore
##

SRC     =       ./src/main.c			\
		./src/evenement.c		\
		./src/aff_pix_img.c		\
		./src/sound.c			\
		./src/pic.c			\
		./src/allu.c			\
		./src/rec.c			\
		./src/ia.c			\
		./src/ia_test.c			\
		./src/key_and_init.c		\
		./src/allu_action.c		\
		./src/disp_and_curs.c		\
		./src/allu_draw.c

OBJ     =       $(SRC:.c=.o)

NAME    =       allum1

LIB     =       ./lib/my/libmy.a

LIBMINI =	./lib/minilibx/libmlx.a

CC      =       clang

CFLAGS  +=      -W -Wall -Wextra

LDFLAGS	=	-L/usr/lib64/X11 -lXext -lX11 -lm -Llib/my/ -lmy -Llib/minilibx/  -lmlx ./lib/libson.so

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
