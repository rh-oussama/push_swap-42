NAME = push_swap
NAME_B = checker

COMMON_SRC = sort_outils/instruction.c sort_outils/commands.c sort_outils/commands_2.c outils/creat_stack_2.c \
				 outils/creat_stack.c outils/sort.c outils/ft_split.c outils/ft_atol.c sort_outils/tiny_sort.c \
				 sort_outils/concat_arg.c sort_outils/ccleaner.c outils/strdup.c

SRC = $(COMMON_SRC) push_swap.c

SRC_B = $(COMMON_SRC) checker_l/checker.c gnl_c/get_next_line.c gnl_c/get_next_line_utils.c

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m


all: $(NAME)

$(NAME): $(SRC)
	@echo -e "$(GREEN)[+] Compiling push_swap...$(NC)"
	@gcc push_swap.c -c
	@gcc $(FLAGS) -o $(NAME) $(SRC)
	@echo -e "$(GREEN)[+] Push Swap is ready!$(NC)"

bonus: $(NAME_B)

$(NAME_B): $(SRC_B)
	@echo -e "$(GREEN)[+] Compiling checker...$(NC)"
	@gcc $(FLAGS) -o $(NAME_B) $(SRC_B)
	@echo -e "$(GREEN)[+] checker is ready!$(NC)"

fclean: clean
	@echo -e "$(RED)[-] Removing Push Swap$(NC)"
	@echo -e "$(RED)[-] Removing checker$(NC)"
	@rm -f $(NAME) $(NAME_B)

clean:
	@echo -e "$(RED)[-] cleaning object file$(NC)"
	@rm -f push_swap.o
re: fclean all

.PHONY: all bonus fclean re clean