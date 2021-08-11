#include "push_swap.h"

void	swap_numbers(t_number *a, t_number *b)
{
	t_number	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_st *a, t_list **lst)
{
	t_number	tmp;

	tmp = a->numbers[a->size - 1];
	a->numbers[a->size - 1] = a->numbers[a->size - 2];
	a->numbers[a->size - 2] = tmp;
	ft_lstadd_back(lst, ft_lstnew("sa"));
}

void	sb(t_st *b, t_list **lst)
{
	t_number	tmp;

	tmp = b->numbers[b->size - 1];
	b->numbers[b->size - 1] = b->numbers[b->size - 2];
	b->numbers[b->size - 2] = tmp;
	ft_lstadd_back(lst, ft_lstnew("sb"));
}

void	ss(t_st *a, t_st *b, t_list **lst)
{
	t_number	tmp;

	tmp = a->numbers[a->size - 1];
	a->numbers[a->size - 1] = a->numbers[a->size - 2];
	a->numbers[a->size - 2] = tmp;
	tmp = b->numbers[b->size - 1];
	b->numbers[b->size - 1] = b->numbers[b->size - 2];
	b->numbers[b->size - 2] = tmp;
	ft_lstadd_back(lst, ft_lstnew("ss"));
}

void	ra(t_st *a, t_list **lst)
{
	t_number	tmp;
	size_t		i;

	tmp = a->numbers[a->size - 1];
	i = -1;
	while (++i < a->size)
		swap_numbers(&(a->numbers[i]), &tmp);
	ft_lstadd_back(lst, ft_lstnew("ra"));
}
