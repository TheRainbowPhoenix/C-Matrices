INC_DIR= /include
SRC_DIR= ./src
OBJ_DIR= ./obj
SRC=			./src/Main.c \
			./src/MatArith.c \
			./src/MatIO.c \

OBJ=			$(SRC:.c=.o)

DEPS=			$(INC_DIR)/MatArith.h $(INC_DIR)/MatIO.h

NAME=			 MultMat

CFLAGS=			-Wall -Wextra -Werror -ansi -pedantic -I$(INC_DIR)

all:			$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
