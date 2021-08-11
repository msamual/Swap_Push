#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
}

int	checker(int ac, char **av, int debug)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack();
	stack_b = new_stack();
	i = ac;
	while (--i)
	{
		if (i == 1 && debug != 0)
			break ;
		if (!is_number(av[i]))
			return (puterror("Error\n", 2));
		push(stack_a, ft_atoi(av[i]));
	}
	if (check_duplicates(stack_a))
		return (puterror("Error\n", 2));
	if (read_command(stack_a, stack_b, debug))
		return (puterror("Error\n", 1));
	if (check_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (!ft_strcmp(av[1], "-v"))
		return (checker(ac, av, 1));
	return (checker(ac, av, 0));
}
