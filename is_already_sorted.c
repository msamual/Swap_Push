#include "push_swap.h"

int	is_already_sorted(t_st *a)
{
	size_t	i;

	i = 0;
	while (++i < a->size)
	{
		if (a->numbers[i].n > a->numbers[i - 1].n)
			return (0);
	}
	return (1);
}
