# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 09:23:07 by lebeyssa          #+#    #+#              #
#    Updated: 2026/01/17 14:07:41 by lebeyssa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := cc
FLAG := -Wall -Wextra -Werror -g
INC := -I. -Ilibft -Iprintf -Iblock_based -Iget_next_line -Ichunk_based -Iradix
NAME := push_swap
OBJ_DIR := .objet
SRC := main.c bubble_sort.c rules_a.c rules_b.c rules_both.c\
		block_based/block_based_sort.c block_based/sorting_copy.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		parsing.c action_list.c chunk_based/chunk_sort.c chunk_based/chunk_sort_utils.c\
		chunk_based/chunk_sort_utils_find.c radix/radix.c radix/radix_utils.c\
		disorder.c insertion/insertion_sort.c bench.c adaptive.c init_main.c main_utils.c

BONUS := checker 
SRC_BONUS := checker/checker.c bubble_sort.c rules_a.c rules_b.c rules_both.c\
		block_based/block_based_sort.c block_based/sorting_copy.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		parsing.c action_list.c chunk_based/chunk_sort.c chunk_based/chunk_sort_utils.c\
		chunk_based/chunk_sort_utils_find.c radix/radix.c radix/radix_utils.c\
		disorder.c insertion/insertion_sort.c bench.c adaptive.c init_main.c main_utils.c\
		checker/checker_utils.c

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(patsubst %.c, %.o, $(SRC_BONUS))
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(OBJ_BONUS))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))




LIBFT := libft/libft.a
PRINTF := printf/libftprintf.a
LIBS := $(LIBFT) $(PRINTF)

all : $(NAME)

bonus : $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBS)
	$(CC) $(FLAG) $(OBJS_BONUS) $(LIBS) -o $(BONUS)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(FLAG) $(OBJS) $(LIBS) -o $(NAME)

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
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C libft fclean --no-print-directory
	$(MAKE) -C printf fclean --no-print-directory

re : fclean all

re_bonus : fclean bonus

.PHONY : clean fclean re all bonus