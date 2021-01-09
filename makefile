CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c		\
		fill_tab1.c		\
		fill_tab2.c		\
		tools1.c		\
		tools2.c		\
		tools3.c		\
		manage_char.c	\
		manage_str.c	\
		manage_hexa.c	\
		manage_int.c	\
		manage_add.c	\


INC = ft_printf.h
AR = ar -rc
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
all : $(NAME)
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean :
	rm -rf $(OBJ) $(OBJ_B)
fclean : clean
	rm -rf $(NAME)
re : fclean all