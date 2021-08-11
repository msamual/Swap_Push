#include "push_swap.h"

void	a_swap(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)b;
	if (a->size < 2)
		return ;
	tmp = a->numbers[a->size - 1];
	a->numbers[a->size - 1] = a->numbers[a->size - 2];
	a->numbers[a->size - 2] = tmp;
}

void	**init_function_array(void)
{
	void	**f;

	f = malloc(sizeof(void *) * 11);
	f[0] = a_swap;
	f[1] = b_swap;
	f[2] = sa_and_sb;
	f[3] = push_a;
	f[4] = push_b;
	f[5] = rotate_a;
	f[6] = rotate_b;
	f[7] = ra_and_rb;
	f[8] = reverse_rotate_a;
	f[9] = reverse_rotate_b;
	f[10] = rra_and_rrb;
	return (f);
}

int	find_command(char *str)
{
	if (!ft_strcmp(str, "sa"))
		return (0);
	else if (!ft_strcmp(str, "sb"))
		return (1);
	else if (!ft_strcmp(str, "ss"))
		return (2);
	else if (!ft_strcmp(str, "pa"))
		return (3);
	else if (!ft_strcmp(str, "pb"))
		return (4);
	else if (!ft_strcmp(str, "ra"))
		return (5);
	else if (!ft_strcmp(str, "rb"))
		return (6);
	else if (!ft_strcmp(str, "rr"))
		return (7);
	else if (!ft_strcmp(str, "rra"))
		return (8);
	else if (!ft_strcmp(str, "rrb"))
		return (9);
	else if (!ft_strcmp(str, "rrr"))
		return (10);
	else
		return (-1);
}
