# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 09:23:07 by lebeyssa          #+#    #+#              #
#    Updated: 2025/12/18 11:27:53 by lebeyssa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := cc
FLAG := -Wall -Wextra -Werror -g
INC := push_swap.h
NAME := push_swap
OBJ_DIR := .objet
SRC := main.c bubble_sort.c rules_a.c rules_b.c rules_both.c\
		ft_utile.c insertion_sort.c chunk_sort.c chunk_test.c
	
OBJ := $(patsubst %.c, %.o, $(SRC))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT := libft/libft.a
PRINTF := printf/libftprintf.a
LIBS := $(LIBFT) $(PRINTF)


all : $(NAME)

$(NAME) : $(OBJS) $(SRC) $(INC) $(LIBS) Makefile
	$(CC) $(FLAG) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I libft -I printf -I $(INC) -c $< -o $@

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

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