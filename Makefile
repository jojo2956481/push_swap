# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 09:23:07 by lebeyssa          #+#    #+#              #
#    Updated: 2025/12/09 13:12:21 by lebeyssa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := cc
FLAG := -Wall -Wextra -Werror
INC := push_swap.h
NAME := push_swap
AR := ar rcs
OBJ_DIR := .objet
SRC := 
	
OBJ := $(patsubst %.c, %.o, $(SRC))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT := libft/libft.a
PRINTF := printf/libftprintf.a
LIBS := $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

all : $(NAME)

$(NAME) : $(OBJS) $(SRC) $(INC) $(LIBS) Makefile
	@$(AR) $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I libft -I printf -I $(INC) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) 
	make -C libft clean
	make -C printf clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

re : fclean all

.PHONY : clean fclean re all