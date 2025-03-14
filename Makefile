NAME1 = server
NAME2 = client
NAME1_BONUS = server_bonus
NAME2_BONUS = client_bonus

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

all: libft $(NAME1) $(NAME2)

libft:
	@make -C libft

$(NAME1): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Server project successfully built!"

$(NAME2): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Client project successfully built!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: libft $(NAME1_BONUS) $(NAME2_BONUS)

$(NAME1_BONUS): $(OBJS_SERVER_BONUS)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "Server_bonus project successfully built!"

$(NAME2_BONUS): $(OBJS_CLIENT_BONUS)
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
	@rm -f $(NAME1) $(NAME2) $(NAME1_BONUS) $(NAME2_BONUS)
	@make -C libft fclean
	@echo "Executables and libraries removed."

re: fclean all

.PHONY: all clean fclean re bonus libft

