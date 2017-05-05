# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 23:16:20 by cde-laro          #+#    #+#              #
#    Updated: 2017/05/05 06:15:16 by cde-laro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D
INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs
LIB_DIR = libft
MLX_DIR = minilibx_macos
FLAGS = -g -Wall -Wextra -Werror -Ofast
INC = -I includes/
LIB = -L $(LIB_DIR) -lft
MLX = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
CC = gcc $(FLAGS) $(INC)
COLOR = \0033[1;35m

SRC_FT = main \
		 init \
		 extract \
		 img_draw \
		 wolf \
		 hook \
		 move \
		 skybox \
		 useful_functions \
		 txt_display \
		 xpm \
		 map_builder \
		 textures \
		 init_txt

OBJ = $(SRC_FT:%=$(OBJ_DIR)/%.o)
SRC = $(SRC_FT:%=$(SRC_DIR)/%.c)

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\t\0033[1;30m[All OK]\0033[0;37m"

$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(COLOR)Creating: \t\t\0033[0;32m$@\0033[0;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJ_DIR) $(SRC)
	@$(MAKE) $(OBJ)
	@echo "$(COLOR)Objects of $(NAME)\t\t\0033[0;32m[Created]\0033[0;37m"
	@make -j -C $(LIB_DIR)
	@afplay resources/compile.mp3 &
	@make -j -C $(MLX_DIR)
	@$(CC) $(LIB) $(OBJ) $(MLX) -o $@
	@echo "$(COLOR)$(NAME)\t\t\t\0033[0;32m[Created]\0033[0;37m"


clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(COLOR)Objects of $(NAME)\t\t\0033[0;31m[Deleted]\0033[0;37m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(MLX_DIR)
	@echo "$(COLOR)$(NAME)\t\t\t\0033[0;31m[Deleted]\0033[0;37m"

re: fclean all

.PHONY: all clean fclean re
