# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 14:25:21 by dbraga-b          #+#    #+#              #
#    Updated: 2023/01/16 14:25:22 by dbraga-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIBFT = ./libft.a
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SRC_SERVER = src/server.c 
OBJ_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT = src/client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)


SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SERVER_BONUS = src/server_bonus.c 
OBJ_SERVER_BONUS= $(SRC_SERVER_BONUS:.c=.o)

SRC_CLIENT_BONUS = src/client_bonus.c
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft
$(SERVER): $(OBJ_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o server
$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o client

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT) 
		$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o server_bonus
$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o client_bonus

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
		$(RM) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(SERVER) $(CLIENT)
		$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)