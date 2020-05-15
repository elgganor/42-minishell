NAME=minishell

INC=-I./inc -I./libft/inc
FLAGS=-Wall -Wextra -Werror
LIB=-L./libft -lft

PARSING=parsing/split_command.c
UTILS=utils/free_functions.c
SRC=$(PARSING) \
	$(UTILS) \
	minishell.c

SRCS=$(addprefix ./src/, $(SRC))
OBJS=$(SRCS:.c=.o)




all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\033[0;34mBuilding minishell... \033[0m"
	@make objets
	@gcc $(FLAGS) $(INC) -o $(NAME) $(OBJS) $(LIB)
	@make clean -C libft
	@echo "\033[1;34mminishell [OK]\n \033[0m"

objets: $(OBJS)

%.o: %.c
	@echo "\033[0;32mCompilation of $< \033[0m"
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJS)

mrproper: clean
	@make fclean -C libft

fclean: clean mrproper
	@echo "\033[0;31mCleaning minishell project... \033[0m"
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re mrproper