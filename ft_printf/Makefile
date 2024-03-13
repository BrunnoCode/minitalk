NAME =	libftprintf.a

INCL = ft_printf.h

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		
%.o: %.c $(INCL) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
