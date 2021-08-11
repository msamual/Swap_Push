#include "push_swap.h"

void	rotate_dist_a(t_st *a, int dist, t_list **lst)
{
	if (dist == 0)
		;
	else if (dist > 0)
	{
		while (dist--)
			ra(a, lst);
	}
	else
	{
		while (dist++)
			rra(a, lst);
	}
}

void	rotate_dist_b(t_st *b, int dist, t_list **lst)
{
	if (dist == 0)
		;
	else if (dist > 0)
	{
		while (dist--)
			rb(b, lst);
	}
	else
	{
		while (dist++)
			rrb(b, lst);
	}
}

void	turn_in_place(t_st *a, int max, t_list **lst)
{
	size_t	i;
	size_t	dist;

	i = a->size - 1;
	while (a->numbers[i].n != max)
		i--;
	if (i >= a->size - i)
	{
		dist = a->size - i - 1;
		rotate_dist_a(a, dist, lst);
	}
	else
		rotate_dist_a(a, -i - 1, lst);
}

int	get_min_path_to_insert(t_st *a, t_number n)
{
	int	cur;
	int	next;
	int	i;

	i = -1;
	while (++i < (int)a->size)
	{
		cur = a->numbers[i].n;
		if (i == (int)a->size - 1)
			next = a->numbers[0].n;
		else
			next = a->numbers[i + 1].n;
		if ((cur > n.n && (n.n > next || next > cur))
			|| (next > cur && n.n > next))
		{
			if (i >= ((int)a->size - 1) / 2)
				return (a->size - i - 1);
			else
				return (-i - 1);
		}
	}
	return (0);
}

void	insert_number_to_place(t_st *a, t_st *b, t_list **lst)
{
	int	dist;

	dist = get_min_path_to_insert(a, b->numbers[b->size -1]);
	rotate_dist_a(a, dist, lst);
	pa(a, b, lst);
}
