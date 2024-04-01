# BINARY
CLIENT = client 
SERVER = server 

# libft
LIBFT = libft/libft.a
C_SRC = src/ft_client.c
S_SRC = src/ft_server.c

OBJ_C = $(C_SRC:.c=.o)
OBJ_S = $(S_SRC:.c=.o)

CC = gcc -g -fsanitize=address 
CFLAGS = -Wall -Werror -Wextra
INC = -I src -I libft
RM = rm -rf

# Colors
GREEN = \033[0;32m
RESET = \033[0m

all: $(CLIENT) $(SERVER)
	@echo "$(GREEN)Compilation completed successfully.$(RESET)"

$(OBJ_C): $(C_SRC)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_S): $(S_SRC)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(CLIENT): $(OBJ_C)
	@make -C libft -s
	@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(CLIENT) 

$(SERVER): $(OBJ_S)
	@make -C libft -s
	@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(SERVER) 

clean:
	@make clean -C libft -s
	@$(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	@make fclean -C libft -s
	@$(RM) $(CLIENT) $(SERVER)
	@echo "$(GREEN)Cleanup completed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
