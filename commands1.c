#include "push_swap.h"

void	rotate_b(t_stack *a, t_stack *b)
{
	int		tmp;
	size_t	i;

	(void)a;
	if (b->size < 2)
		return ;
	tmp = b->numbers[b->size - 1];
	i = -1;
	while (++i < b->size)
		swap(&tmp, &(b->numbers[i]));
}

void	ra_and_rb(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}

void	reverse_rotate_a(t_stack *a, t_stack *b)
{
	int		tmp;
	size_t	i;

	(void)b;
	if (a->size < 2)
		return ;
	tmp = a->numbers[0];
	i = a->size;
	while (i--)
		swap(&tmp, &(a->numbers[i]));
}

void	reverse_rotate_b(t_stack *a, t_stack *b)
{
	int		tmp;
	size_t	i;

	(void)a;
	if (b->size < 2)
		return ;
	tmp = b->numbers[0];
	i = b->size;
	while (i--)
		swap(&tmp, &(b->numbers[i]));
}

void	rra_and_rrb(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a, b);
	reverse_rotate_b(a, b);
}
