#include "push_swap.h"

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	measure_distances(t_st *a, t_st *b)
{
	int	i;
	int	ra;
	int	rra;

	i = -1;
	rra = 1;
	ra = b->size - 1;
	while (++i < (int)b->size)
	{
		b->numbers[i].dist_in_a = get_min_path_to_insert(a, b->numbers[i]);
		if (rra < ra)
			b->numbers[i].dist_in_b = -rra;
		else
			b->numbers[i].dist_in_b = ra;
		b->numbers[i].dist = absolute(b->numbers[i].dist_in_a)
			+ absolute(b->numbers[i].dist_in_b);
		rra++;
		ra--;
	}
}

int	get_min_dist(t_st *b)
{
	int	i;
	int	min;
	int	res;

	i = -1;
	min = 2147483647;
	res = 0;
	while (++i < (int)b->size)
	{
		if (b->numbers[i].dist < min)
		{
			res = i;
			min = b->numbers[i].dist;
		}
	}
	return (res);
}

void	prepare_to_take(t_st *a, t_st *b, t_list **lst)
{
	int	i;

	if (a)
		;
	i = get_min_dist(b);
	rotate_dist_b(b, b->numbers[i].dist_in_b, lst);
}

void	sort_all(t_st *a, t_st *b, t_stack *c, t_list **lst)
{
	int	pivot;

	pivot = c->numbers[c->size / 2];
	while (a->size > 3)
	{
		pb(a, b, lst);
		if (b->numbers[b->size - 1].n > pivot)
			rb(b, lst);
	}
	sort_three_elements(a, lst);
	while (b->size)
	{
		measure_distances(a, b);
		prepare_to_take(a, b, lst);
		insert_number_to_place(a, b, lst);
	}	
}
