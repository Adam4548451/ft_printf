CC = clang
FLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a


LIBFT = ./libft/*.c
PARSING = ./parsing/*.c
UTILS = ./utils/*.c
SRC = $(wildcard *.c) $(PARSING) $(UTILS) $(LIBFT)
SRC_BONUS = 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(CC) -c $(FLAGS) $(SRC_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME

test:
	$(CC) -fsanitize=address $(SRC)
	./a.out | cat -e
debug:
	$(CC) -g $(SRC)
	gdb ./a.out