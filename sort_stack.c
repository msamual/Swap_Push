#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_min_dist(t_stack *a, int x, int *dir)
{
	int	i;
	int	up;
	int	down;

	down = 0;
	i = a->size;
	while (i--)
	{
		if (a->numbers[i] == x)
			break ;
		down++;
	}
	i = -1;
	up = 0;
	while (++i < (int)a->size)
	{
		up++;
		if (a->numbers[i] == x)
			break ;
	}
	if (down <= up)
		*dir = 0;
	else
		*dir = 1;
	return (min(up, down));
}

int	get_min_distance(int *com, t_stack *a, int hi, int lo)
{
	int	hi_dist;
	int	lo_dist;
	int	hi_direction;
	int	lo_direction;

	hi_dist = get_min_dist(a, hi, &hi_direction);
	lo_dist = get_min_dist(a, lo, &lo_direction);
	if (lo_dist < hi_dist)
	{
		if (lo_direction)
			*com = 0;
		else
			*com = 1;
		return (lo_dist);
	}
	else
	{
		if (hi_direction)
			*com = 2;
		else
			*com = 3;
		return (hi_dist);
	}
}

void	find_elem(t_stack *a, t_stack *b, t_stack *c, t_list **com)
{
	int	hi;
	int	lo;
	int	command_code;
	int	dist;

	hi = c->numbers[c->size - 1];
	lo = c->numbers[0];
	dist = get_min_distance(&command_code, a, hi, lo);
	rotate_loop(a, dist, command_code, com);
	push_and_rotate(a, b, c, com);
}

void	sort_stack(t_stack *a, t_stack *b, t_stack *c)
{
	t_list	*commands;
	int		max;

	max = c->numbers[c->size - 1];
	commands = NULL;
	while (c->size)
	{
		find_elem(a, b, c, &commands);
		pop(c);
	}
	push_all(b, a, "pa", &commands);
	turn_into_place(a, max, &commands);
	write_commands(commands);
	clear_list(&commands);
}
