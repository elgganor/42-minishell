NAME=minishell

INC=-I./inc -I./libft/inc
FLAGS=-Wall -Wextra -Werror
# FLAGS=-Wall -Wextra -Werror -fsanitize=address
LIB=-L./libft -lft

PARSING=parsing/split_input.c \
		parsing/split_command.c \
		parsing/is_builtin.c \
		parsing/take_input.c \
		parsing/redirection.c \
		parsing/env.c \
		parsing/pipe.c \
		parsing/quotes.c

EXECUTION=execution/execute_commands.c \
		execution/run_builtin.c \
		execution/run_system_program.c \
		execution/process_commands.c

INITIALISATION=initialisation/show_prompt.c \
		initialisation/env.c

UTILS=utils/free_functions.c \
		utils/error_handler.c \
		utils/redirection.c \
		utils/pipe.c

BUILTIN=builtin/pwd.c \
        builtin/cd.c \
        builtin/exit.c \
        builtin/echo.c \
        builtin/env.c \
        builtin/export.c \
        builtin/unset.c

SRC=minishell.c \
	$(PARSING) \
	$(EXECUTION) \
	$(UTILS) \
	$(BUILTIN) \
	$(INITIALISATION)

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
