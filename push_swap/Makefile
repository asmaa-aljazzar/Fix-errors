# Color
RESET	=	\033[0m
RED	=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m


# Standard
NAME	=	push_swap

# Compiler and Flags
CC		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -g -I
RM 		= 	rm -f

# Directories
INC			= 	includes/
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
LIBFT		=	./libft/libft.a

# Source Files
COMMANDS_DIR	= 	$(SRCS_DIR)commands/swap.c\
					$(SRCS_DIR)commands/sort_three.c\
					$(SRCS_DIR)commands/rotate.c\
					$(SRCS_DIR)commands/rotate_rev.c\
					$(SRCS_DIR)commands/sorting.c\
					$(SRCS_DIR)commands/moving.c\
					$(SRCS_DIR)commands/push.c

PUSH_SWAP_DIR	= 	$(SRCS_DIR)push_swap/push_swap.c\
					$(SRCS_DIR)push_swap/errors_handling.c\
					$(SRCS_DIR)push_swap/stack_init.c\
					$(SRCS_DIR)push_swap/stack_utils.c\
					$(SRCS_DIR)push_swap/init_atob.c\
					$(SRCS_DIR)push_swap/init_btoa.c

SRCS	= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJS	= $(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

$(LIBFT):
	make -C ./libft

# Build Rules
start:
	make all

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\n[ $(YELLOW)$(NAME) $(RESET)] $(GREEN)has been created!$(RESET)\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "Creating $(YELLOW)$(@D)$(RESET)/ $(GREEN)$(@F)$(RESET)"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C libft
	@echo "$(BLUE)Obj files cleaned.$(RESET)"

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	@echo "$(BLUE) Binary files cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
