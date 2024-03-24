# BINARY
CLIENT = client 
SERVER = server 

# ft_printf y libft variables
LIBFTPRINTF = ft_printf/libftprintf.a
FT_PRINTFDIR = ft_printf
LIBFT = libft/libft.a
LIBFTDIR = libft

# minitalk variables

SRC_C = ft_client.c
SRC_S = ft_server.c 
OBS_C = ft_client.o
OBS_S = ft_server.o 
INC = ft_minitalk.h

# compiling variables

CC =	gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# colors
GREEN		=	\e[38;5;118m]
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m]
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)

all: $(LIBFT) $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBS_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ $(OBS_S) --silent
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(OBS_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ $(OBS_C) --silent
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@ --silent

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory

$(LIBFTPRINTF):
	@$(MAKE) -C $(FT_PRINTFDIR) --no-print-directory

clean:
	@ $(MAKE) clean -C $(LIBFTDIR) --no-print-directory --silent
	@ $(MAKE) clean -C $(FT_PRINTFDIR) --no-print-directory --silent
	@ $(RM) $(OBS_S) $(OBS_C) --silent
	@printf "$(_INFO) ...objects files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTDIR) --no-print-directory --silent
	@ $(MAKE) fclean -C $(FT_PRINTFDIR) --no-print-directory --silent
	@ $(RM) $(CLIENT) $(SERVER) --silent
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re