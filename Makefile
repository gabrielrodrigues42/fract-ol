# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 18:51:03 by gandrade          #+#    #+#              #
#    Updated: 2021/11/20 14:57:34 by gandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang
CFLAGS = -O3 -Wall -Wextra -Werror
SAN = -g3 -fsanitize=address

RM = rm -rf
MKDIR = mkdir -p

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SYS_FLAGS = -lXext -lX11 -lm

INCLUDE_DIR = ./include $(MLX_DIR) $(LIBFT_DIR)
INCLUDE = $(addprefix -I, $(INCLUDE_DIR))

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC_FILES = main.c \
            parse_args.c \
            parse_julia.c \
            parse_complex.c \
            parse_complex_utils.c \
            print_help.c \
            create_fractol.c \
            set.c \
            render_frame.c \
            window_to_viewport.c \
            calculate_mandelbrot.c \
            calculate_burningship.c \
            calculate_julia.c \
            colors.c \
            image.c \
            hooks.c \
            zoom.c \
            shift.c \
            destroyer.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) $(SYS_FLAGS) $(INCLUDE) -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

norm:
	norminette libft include src

san:
	$(CC) $(CFLAGS) $(SAN) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) $(SYS_FLAGS) $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re norm san
