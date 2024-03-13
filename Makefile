# BINARY
NAME =
CLIENT = client 
SERVER = server 

# ft_printf variables
LIBFTPRINTF = ft_printf/libftprintf.a
FT_PRINTFDIR = ft_printf

# minitalk variables

SRC_C = ft_client.c
SRC_S = ft_server.c 
OBS_C = ft_client.o
OBS_S = ft_server.o 
INC = ft_minital.h

# compiling variables

CC =	gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# colors
GREEN		=	\e[38;5;118m]
YELLOW		=	\e[38;5;226m]
RESET		=	\e[0m]
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBS_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@