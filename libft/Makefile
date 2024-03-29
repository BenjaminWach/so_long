# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 11:49:13 by bwach             #+#    #+#              #
#    Updated: 2024/02/17 17:05:46 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

OBJ_LB		= $(LBF_SRC:.c=.o)
LBF_SRC		=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_striteri.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c get_next_line_utils.c

PRINTF_SRCS	=	ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_printf_utils.c \
				ft_printf.c 	
PRINTF_DIR	=	printf/
FT_PRINTF		=	$(addprefix $(PRINTF_DIR), $(PRINTF_SRCS))
OBJ_P		=	$(FT_PRINTF:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ_LB) $(OBJ_P)
	@ar rcs $@ $^

%.o:		%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:	
	@rm -rf $(OBJ_LB)
	@rm -rf $(OBJ_P)

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re