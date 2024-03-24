# BINARY
CLIENT = client 
SERVER = server 

# ft_printf and libft
PRINTF = libftprintf.a
LIBFT = libft.a
C_SRC = ft_client.c
S_SRC = ft_server.c
SRCDIR = src/
# add prefix src/ft_client and ft_server
SRC_C = $(addprefix $(SRCDIR), $(C_SRC))
SRC_S = $(addprefix $(SRCDIR), $(S_SRC))

OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}

CC =	cc
CFLAGS = -Wall -Werror -Wextra
INC = -I include
RM = rm -rf

all: $(CLIENT) $(SERVER)
# colors
GREEN		=	\e[38;5;118m]
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m]
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)