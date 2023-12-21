# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:26:01 by bwach             #+#    #+#              #
#    Updated: 2023/12/21 16:16:46 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color
CYAN = \033[0;36m
DEFAULT = \033[0m

#Project_Name
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

#Dossiers
LIBFT_DIR = ./libft
SRC_DIR = ./sources
INC_DIR = ./include
MLX_DIR = ./mlx

PRINTF = printf
BIN = so_long

OBJ = $(SRC_FILES:.c=.o)

#Detect the OS:
UNAME_S := $(shell uname -s)

#SET the flags
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -lmlx -lXext -lX11
else
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

all: 
	@echo "$(CYAN)\nCompilation starting .. 😅\n $(DEFAULT)"
	@make $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lmlx -lmxl -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft	
	@echo "$(CYAN)\nCompilation done 🤡\n $(DEFAULT)"

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@

norminette: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_FILES) $(LIBFT_DIR)/*.c
	@norminette -R CheckDefine $(LIBFT_DIR)/*.c
	@echo "$(CYAN)\tNorminette done and validated faggot 🤣\n $(DEFAULT)"

clean: 
	$(RM) $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	@make clean -C ${LIBFT_DIR}
	@echo "$(CYAN)\tClean done\n $(DEFAULT)"
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	@echo "$(CYAN)\tFclean done\n $(DEFAULT)"

re: fclean all

.PHONY: clean fclean re norminette 