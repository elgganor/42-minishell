NAME=minishell

INC=-I./inc -I./libft/inc
FLAGS=-Wall -Wextra -Werror
LIB=-L./libft -lft

SRC=

SRCS=$(addprefix ./src/, $(SRC))
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo "\033[0;34mBuilding minishell... \033[0m"
	@gcc $(FLAGS) $(INC) -o $(NAME) $(OBJS) $(LIB)

%.o: %.c
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean: $(OBJS)
	@rm -f $(OBJS)

mrproper: clean
	@make fclean -C libft

fclean: clean mrproper
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: