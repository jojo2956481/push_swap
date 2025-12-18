# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 15:05:06 by lebeyssa          #+#    #+#              #
#    Updated: 2025/12/17 13:14:58 by lebeyssa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := cc
FLAG := -Wall -Wextra -Werror
INC := ft_printf.h
NAME := libftprintf.a
AR := ar rcs
OBJ_DIR := .objet
SRC := ft_dispatch.c ft_printf.c ft_putstr.c ft_putnbr.c\
	ft_putnbr_base.c ft_putptr.c ft_putnbr_unsigned.c ft_util.c
OBJ := $(patsubst %.c, %.o, $(SRC))

OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

all : $(NAME)

$(NAME) : $(OBJS) $(SRC) $(INC) Makefile
	@$(AR) $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all