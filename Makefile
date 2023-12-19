# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:26:01 by bwach             #+#    #+#              #
#    Updated: 2023/12/19 15:56:46 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color
CYAN = \033[0;36m
DEFAULT = \033[0m

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
LIBFT_DIR = libft
PRINTF = printf
BIN = push_swap

SRC_FILES = 

OBJ = $(SRC_FILES:.c=.o)

all: 
	@echo "$(CYAN)\nCompilation starting .. 😅\n $(DEFAULT)"
	@make $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft	
	@echo "$(CYAN)\nCompilation done 🤡\n $(DEFAULT)"

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@

norminette: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_FILES) $(LIBFT_DIR)/*.c
	@norminette -R CheckDefine $(LIBFT_DIR)/*.c
	@echo "$(CYAN)\tNorminette done and validated faggot 🤣\n $(DEFAULT)"

clean: 
	$(RM) $(OBJ)
	@make clean -C ${LIBFT_DIR}
	@echo "$(CYAN)\tClean done\n $(DEFAULT)"
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	@echo "$(CYAN)\tFclean done\n $(DEFAULT)"

re: fclean all

.PHONY: clean fclean re norminette 