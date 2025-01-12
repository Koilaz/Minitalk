# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:26:31 by leo               #+#    #+#              #
#    Updated: 2025/01/09 15:38:02 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -g

SRC1 = server.c
SRC2 = client.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

EXE1 = server
EXE2 = client

LIBFTPRINTF = libftprintf.a

# Répertoire contenant la bibliothèque
LIBDIR = .

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) -lftprintf

$(EXE2): $(OBJ2) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(EXE1) $(EXE2)

re: fclean all
