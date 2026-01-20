# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 09:23:07 by lebeyssa          #+#    #+#              #
#    Updated: 2026/01/19 16:31:06 by lebeyssa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := cc
FLAG := -Wall -Wextra -Werror
INC := -I. -Ilibft -Iprintf -Iget_next_line -Ichunk_based -Iradix -Isort_under_5
NAME := push_swap
OBJ_DIR := .objet
SRC := main.c rules_a.c rules_b.c rules_both.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		parsing.c chunk_based/chunk_sort.c chunk_based/chunk_sort_utils.c\
		chunk_based/chunk_sort_utils_find.c radix/radix.c radix/radix_utils.c\
		disorder.c insertion/insertion_sort.c bench.c adaptive.c init_main.c main_utils.c\

BONUS := checker 
SRC_BONUS := checker_bonus/checker_bonus.c rules_a.c rules_b.c rules_both.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		parsing.c chunk_based/chunk_sort.c chunk_based/chunk_sort_utils.c\
		chunk_based/chunk_sort_utils_find.c radix/radix.c radix/radix_utils.c\
		disorder.c insertion/insertion_sort.c bench.c adaptive.c init_main.c main_utils.c\
		checker_bonus/checker_utils_bonus.c
HEADERS := push_swap.h checker_bonus/checker_bonus.h chunk_based/chunk_sort.h radix/radix.h\
			get_next_line/get_next_line.h

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
	$(CC) $(FLAG) $(OBJS_BONUS) $(LIBS) -Ichecker -o $(BONUS)

$(NAME): $(OBJS) $(LIBS) 
	$(CC) $(FLAG) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
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

.PHONY : clean fclean re all bonus