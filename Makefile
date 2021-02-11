CC = clang
FLAGS = -Wall -Wextra -Werror
SRC = 
SRC_BONUS = 
NAME = ft_printf.a
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