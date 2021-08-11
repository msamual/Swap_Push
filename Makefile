CHECKER		= checker
PUSH		= push_swap
LIB			= libft/libft.a
FLAGS		= -Wall -Wextra -Werror -g

SRC			= find_command.c execute_command.c commands.c \
			commands1.c read_command.c sort_array.c \
			rotate.c write_commands.c s_stack.c print_stacks.c \
			marking.c is_already_sorted.c sorting.c ps_com.c \
			ps_com1.c insert_number_to_place.c optimize.c \
			optimize1.c sort_all.c
OBJ			= $(SRC:.c=.o)
HEADER		= includes/push_swap.h
INC			= includes/

all:  $(lib) $(CHECKER) $(PUSH)

$(LIB):
	make all -C libft/

$(CHECKER): checker.o $(OBJ) $(LIB)
	gcc $(FLAGS) -o $(CHECKER) checker.o $(OBJ) $(LIB)

$(PUSH): push_swap.o $(OBJ) $(LIB)
	gcc $(FLAGS) -o $(PUSH) push_swap.o $(OBJ) $(LIB)

$(INC):
	make re

checker.o: checker.c $(HEADER)
	gcc $(FLAGS) -c -o checker.o checker.c -I $(INC)

push_swap.o: push_swap.c $(HEADER)
	gcc $(FLAGS) -c -o push_swap.o push_swap.c -I $(INC)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I $(INC)

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ) checker.o push_swap.o

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(CHECKER) $(PUSH)
	rm -f **/a.out
	rm -f a.out
	rm -f $(SHELL_LIB)

re: fclean all
