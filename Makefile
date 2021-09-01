# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 18:51:03 by gandrade          #+#    #+#              #
#    Updated: 2021/09/01 19:04:54 by gandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = clang
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
MKDIR = mkdir -p

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SYS_FLAGS = -lXext -lX11 -lm

INCLUDES_DIR = ./includes $(MLX_DIR) $(LIBFT_DIR)
INCLUDES = $(addprefix -I, $(INCLUDES_DIR))

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS_FILES = main.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(SYS_FLAGS) $(INCLUDES) -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

norm:
	norminette libft includes srcs

.PHONY: all clean fclean re norm
