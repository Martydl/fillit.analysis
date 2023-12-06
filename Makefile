NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	sources/line.c \
		sources/format.c \
		sources/main.c \
		sources/backtracking.c \
		sources/move_piece.c \
		sources/square.c\
		sources/lib1.c \
		sources/lib2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


re: fclean all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

.PHONY: all re clean fclean
