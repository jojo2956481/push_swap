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
INC := -I. -Ilibft -Iprintf -Iblock_based
NAME := push_swap
OBJ_DIR := .objet
SRC := main.c bubble_sort.c rules_a.c rules_b.c rules_both.c\
		block_based/block_based_sort.c block_based/sorting_blocks.c\
		block_based/sorting_copy.c block_based/sorting_copy_utils.c

OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT := libft/libft.a
PRINTF := printf/libftprintf.a
LIBS := $(LIBFT) $(PRINTF)


all : $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(FLAG) $(OBJS) $(LIBS) -o $(NAME) -g

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft --no-print-directory

$(PRINTF):
	$(MAKE) -C printf --no-print-directory

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean --no-print-directory
	$(MAKE) -C printf clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean --no-print-directory
	$(MAKE) -C printf fclean --no-print-directory

re : fclean all

.PHONY : clean fclean re all