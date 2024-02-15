# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:26:01 by bwach             #+#    #+#              #
#    Updated: 2024/02/15 16:02:36 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
CYAN   = \033[0;36m
GREEN = \033[0;32m
RED = \033[0;31m
DEFAULT = \033[0m

#name and aliases
NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L ./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f
PRINTF = printf
BIN = so_long

#FILES AND PATH
HEADER_SRCS	=	so_long.h mlx.h
HEADER_DIR	=	include/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MLX_DIR 	=	mlx/
MLX			=   mlx/libmlx.a

MPATH_SRCS	=	main.c init.c sprites.c hook.c game_loop.c reset_game.c
MPATH_DIR	=	src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

LBFT_DIR	=	libft/
LBFT		=	libft/libft.a

UTIL_SRCS	=	error_gest.c key_gest.c map_gest.c map_data.c map_data_utils.c sprite_pond.c \
				fps.c
UTIL_DIR	=	utils/
UTILS 		=	$(addprefix $(UTIL_DIR), $(UTIL_SRCS))
OBJ_U		=	$(UTILS:.c=.o)

TILES_SRCS	=	background.c walls.c 
TILES_DIR	=	tiles/
TILES		=	$(addprefix $(TILES_DIR), $(TILES_SRCS))
OBJ_T		=	$(TILES:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
	@${CC} ${FLAGS} -Imlx -c $< -o $@ 

all:  $(MLX) $(LBFT) $(NAME) #$(MAKE) norminette
	
norminette:
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(MPATH_DIR) $(UTIL_DIR) $(LBFT_DIR)/*.c
	@norminette -R CheckDefine $(MPATH_DIR) $(UTIL_DIR) $(TILES_DIR) $(LIBFT_DIR)/*.c
	@echo "$(CYAN)\nNorminette done and validated faggot 🤣\n $(DEFAULT)"

$(NAME): $(MLX) $(LBFT) $(OBJ_U) $(OBJ_T) $(OBJ_M)
	@echo "$(GREEN)-------------------------------------$(DEFAULT)"
	@echo "$(CYAN)\n         COMPILING: $(NAME)          \n$(DEFAULT)"
	@echo "$(GREEN)-------------------------------------\n$(DEFAULT)"
	@$(CC) $(MLX_LIB) $(OBJ_U) $(OBJ_T) $(LBFT) $(OBJ_M) $(MLX_FLAGS) -o $(NAME)
	@$(PRINTF) "\r%100s\r$(GREEN)\t$(NAME) created!\n $(DEFAULT)"
	
$(MLX):
	@echo "$(GREEN)-------------------------------------\n$(DEFAULT)"
	@echo -e: "$(GREEN) MLX Compiling\n $(DEFAULT)"
	@echo "$(GREEN)-------------------------------------\n$(DEFAULT)"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

$(LBFT):
	@echo "$(GREEN)-------------------------------------\n$(DEFAULT)"
	@echo -e: "$(GREEN) Libft Compiling\n $(DEFAULT)"
	@echo "$(GREEN)-------------------------------------\n$(DEFAULT)"
	@$(MAKE) -C $(LBFT_DIR)

clean:
	@$(RM) $(OBJ_M)
	@$(RM) $(OBJ_U)
	@$(RM) $(OBJ_T)
	@echo -e: "$(RED)object files deleted!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(LBFT_DIR)
	@echo -e: "$(RED)all deleted!$(DEFAULT)"

re:	fclean all

.PHONY:	all clean fclean bonus re