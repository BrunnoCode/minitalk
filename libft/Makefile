NAME = libft.a

INCL = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_printf.c ft_strlen.c ft_putstr.c error_control.c ft_strjoin.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(INCL) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
