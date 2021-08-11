#include "push_swap.h"

void	execute_command(t_stack *a, t_stack *b, int com, void **mass)
{
	void	(*f)();

	f = mass[com];
	f(a, b);
}

bool	find_int(int n, int *buf, int count)
{
	while (count--)
	{
		if (buf[count] == n)
			return (true);
	}
	return (false);
}

bool	check_duplicates(t_stack *stack)
{
	int	buf[1000];
	int	i;

	i = 0;
	while (i < (int)stack->size)
	{
		if (find_int(stack->numbers[i], buf, i))
			return (true);
		buf[i] = stack->numbers[i];
		i++;
	}
	return (false);
}

bool	check_duplicates_s(t_st *stack)
{
	int	buf[1000];
	int	i;

	i = 0;
	while (i < (int)stack->size)
	{
		if (find_int(stack->numbers[i].n, buf, i))
			return (true);
		buf[i] = stack->numbers[i].n;
		i++;
	}
	return (false);
}
