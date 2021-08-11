#include "push_swap.h"

void	b_swap(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)a;
	if (b->size < 2)
		return ;
	tmp = b->numbers[b->size - 1];
	b->numbers[b->size - 1] = b->numbers[b->size - 2];
	b->numbers[b->size - 2] = tmp;
}

void	sa_and_sb(t_stack *a, t_stack *b)
{
	a_swap(a, b);
	b_swap(a, b);
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		push(a, pop(b));
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		push(b, pop(a));
}

void	rotate_a(t_stack *a, t_stack *b)
{
	int		tmp;
	size_t	i;

	(void)b;
	if (a->size < 2)
		return ;
	tmp = a->numbers[a->size - 1];
	i = -1;
	while (++i < a->size)
		swap(&tmp, &(a->numbers[i]));
}
