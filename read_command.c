#include "push_swap.h"

int	puterror(char *msg, int code)
{
	ft_putstr_fd(msg, 2);
	return (code);
}

bool	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	i = 0;
	while (++i < stack_a->size)
	{
		if (stack_a->numbers[i] > stack_a->numbers[i - 1])
			return (false);
	}
	if (stack_b->size == 0)
		return (true);
	return (false);
}

bool	is_int(char *str)
{
	if (!ft_isdigit_str(str))
		return (false);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (false);
	return (true);
}

int	read_command(t_stack *stack_a, t_stack *stack_b, int debug)
{
	char	*line;
	int		command_number;
	void	**mass;

	line = NULL;
	mass = init_function_array();
	while (get_next_line(0, &line) > 0)
	{
		command_number = find_command(line);
		if (command_number == -1)
			return (1);
		free(line);
		execute_command(stack_a, stack_b, command_number, mass);
		if (debug == 1)
			print_stacks(stack_a, stack_b);
		else if (debug == 2)
			print_stacks(stack_a, stack_b);
	}
	if (debug == 1)
		print_stacks(stack_a, stack_b);
	else if (debug == 2)
		print_stacks(stack_a, stack_b);
	free(line);
	free(mass);
	return (0);
}
