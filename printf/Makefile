CC := cc
CFLAGS := -Wall -Werror -Wextra
DEPFLAGS := -MMD -MP

AR := ar
ARFLAGS := -rcs

NAME := libftprintf.a

SRC := suparg_bonus.c parsing.c man_c.c\
        man_p.c man_u.c assigning_content.c\
        man_base.c lst_std.c lst_gestion.c\
        ft_strndup.c print_basic_case_and_first_bonus.c print_second_bonus.c\
        ft_printf.c man_base_int.c



SRC_DIR := src/
OBJ := $(SRC:.c=.o)
OBJ_DIR := .objs/
OBJS := $(addprefix $(OBJ_DIR), $(OBJ))
LIBFTDIR := libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)
	$(AR) $(ARFLAGS) $@ $(OBJS) $(LIBFTDIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(SRC_DIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFTOBJ):
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) all

.PHONY: bonus
bonus: re

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) clean

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFTDIR) fclean

.PHONY: re
re: fclean all

-include $(ALL_D)
