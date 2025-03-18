# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 22:47:32 by lserghin          #+#    #+#              #
#    Updated: 2025/03/18 00:33:29 by lserghin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = server
NAME_2 = client
NAME_3_BONUS = server_bonus
NAME_4_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

INCLUDES = -Iinclude
INCLUDES_BONUS = -Iinclude_bonus

SRCS_DIR = source
OBJS_DIR = object

SRCS_BONUS_DIR = source_bonus
OBJS_BONUS_DIR = object_bonus

SRC_FILES = server.c client.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_SERVER = $(OBJS_DIR)/server.o
OBJS_CLIENT = $(OBJS_DIR)/client.o

SRC_FILES_BONUS = server_bonus.c client_bonus.c
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, $(SRC_FILES_BONUS))
OBJS_BONUS = $(SRCS_BONUS:$(SRCS_BONUS_DIR)/%.c=$(OBJS_BONUS_DIR)/%.o)
OBJS_SERVER_BONUS = $(OBJS_BONUS_DIR)/server_bonus.o
OBJS_CLIENT_BONUS = $(OBJS_BONUS_DIR)/client_bonus.o

all: libft $(NAME_1) $(NAME_2)

libft:
	@make -C libft

$(NAME_1): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Server project successfully built!"

$(NAME_2): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Client project successfully built!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: libft $(NAME_3_BONUS) $(NAME_4_BONUS)

$(NAME_3_BONUS): $(OBJS_SERVER_BONUS)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Server_bonus project successfully built!"

$(NAME_4_BONUS): $(OBJS_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Client_bonus project successfully built!"

$(OBJS_BONUS_DIR)/%.o: $(SRCS_BONUS_DIR)/%.c
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@make -C libft clean
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME_1) $(NAME_2) $(NAME_3_BONUS) $(NAME_4_BONUS)
	@make -C libft fclean
	@echo "Executables and libraries removed."

re: fclean all

.PHONY: all clean fclean re bonus libft
