AR = ar -rcs
RM = rm -rf

CC = cc
CCFLAGS= -Wall -Werror -Wextra
INCLUDE = ft_printf.h

NAME = libftprintf.a 
SRC = ft_printf.c ft_printf_utils.c ft_strlen.c 
OBJ_SRC=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ_SRC) $(INCLUDE)
	$(AR) $(NAME) $(OBJ_SRC)

%.o:%.c 
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) *.o 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
