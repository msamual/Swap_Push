#include "push_swap.h"

int	get_need_pos(int n, t_stack *c)
{
	int	pos;

	pos = 0;
	while (c->numbers[pos] != n)
		pos++;
	return (pos);
}

void	marking(t_st *a, t_stack *c)
{
	size_t	i;

	i = -1;
	while (++i < a->size)
	{
		a->numbers[i].need = get_need_pos(a->numbers[i].n, c);
		if (a->numbers[i].need == (int)a->size - 1)
			a->numbers[i].max = true;
		else
			a->numbers[i].max = false;
	}
}
