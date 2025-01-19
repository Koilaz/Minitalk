# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarck <lmarck@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 17:27:49 by lmarck            #+#    #+#              #
#    Updated: 2025/01/18 17:27:52 by lmarck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT    = client
NAME_SERVER    = server
NAME_CLIENT_B    = client_bonus
NAME_SERVER_B    = server_bonus


CC             = gcc
CFLAGS         = -Wall -Wextra -Werror

SRC_CLIENT     = client.c
SRC_SERVER     = server.c
SRC_CLIENT_B     = client_bonus.c
SRC_SERVER_B     = server_bonus.c

OBJ_CLIENT     = $(SRC_CLIENT:.c=.o)
OBJ_SERVER     = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_B     = $(SRC_CLIENT_B:.c=.o)
OBJ_SERVER_B     = $(SRC_SERVER_B:.c=.o)

LIBFT_DIR      = ./libft
FT_PRINTF_DIR  = ./ft_printf

LIBFT          = $(LIBFT_DIR)/libft.a
FT_PRINTF      = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)
	@echo "✓ Client compilé avec succès."


$(NAME_SERVER): $(OBJ_SERVER)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)
	@echo "✓ Server compilé avec succès."

bonus: $(NAME_CLIENT_B) $(NAME_SERVER_B)

$(NAME_CLIENT_B): $(OBJ_CLIENT_B)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_B) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT_B)
	@echo "✓ Client bonus compilé avec succès."


$(NAME_SERVER_B): $(OBJ_SERVER_B)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_SERVER_B) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER_B)
	@echo "✓ Server bonus compilé avec succès."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_B) $(OBJ_SERVER_B)
	@echo "✓ Tous les .o ont été supprimés."

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_B) $(NAME_SERVER_B)
	@echo "✓ Les exécutables et librairies ont été supprimés."

re: fclean all

.PHONY: all clean fclean re
