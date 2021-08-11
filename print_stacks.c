#include "push_swap.h"

void	print_three_stacks_s(t_st *a, t_st *b, t_stack *c)
{
	size_t	i;

	i = ft_int_max_three(a->size, b->size, c->size);
	while (i--)
	{
		if (a->size > i)
			printf("%-20d", a->numbers[i].n);
		else
			printf("                    ");
		if (b->size > i)
			printf("%-20d", b->numbers[i].n);
		else
			printf("                    ");
		if (c->size > i)
			printf("%d\n", c->numbers[i]);
		else
			printf("\n");
	}
	printf("size = %-13zusize = %zu\n", a->size, b->size);
	write (1, "----------------------------------------\n", 42);
}
