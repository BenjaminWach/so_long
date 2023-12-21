# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 11:43:49 by bwach             #+#    #+#              #
#    Updated: 2023/12/21 16:11:14 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color
CYAN = \033[0;36m
DEFAULT = \033[0m

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L.
LDLIBS = -lft

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_DIR)
	@ar -x $(LIBFT_DIR)/libft.a
	@make -C $(FT_PRINTF_DIR)
	@ar -x $(shell pwd)/$(FT_PRINTF_DIR)/libftprintf.a
	@make -C $(GNL_DIR)
	@ar -x $(shell pwd)/$(GNL_DIR)/libftgnl.a
	@ar rcs $(NAME) $(OBJ) `find . -name "*.o"`
	
%.o : %.c
	$(CC) $(CFLAGS) -g -I . -c $< -o $@

LIBFT: $(NAME)

clean:
	@$(RM) *.o
	@make clean -C ${LIBFT_DIR}
	@make clean -C ${FT_PRINTF_DIR}
	@make clean -C ${GNL_DIR}
	@echo "$(CYAN)\nCleaning DONE\n$(DEFAULT)"
	
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/libft.a
	@$(RM) libftprintf.a
	@$(RM) libftgnl.a
	@$(RM) __.SYMDEF\ SORTED
	@echo "$(CYAN)\nFclean done\n$(DEFAULT)"
	
re: fclean all

.PHONY: clean fclean re