#include "push_swap.h"

void	rb(t_st *b, t_list **lst)
{
	t_number	tmp;
	size_t		i;

	tmp = b->numbers[b->size - 1];
	i = -1;
	while (++i < b->size)
		swap_numbers(&(b->numbers[i]), &tmp);
	ft_lstadd_back(lst, ft_lstnew("rb"));
}

void	rra(t_st *a, t_list **lst)
{
	t_number	tmp;
	size_t		i;

	tmp = a->numbers[0];
	i = a->size;
	while (i--)
		swap_numbers(&(a->numbers[i]), &tmp);
	ft_lstadd_back(lst, ft_lstnew("rra"));
}

void	rrb(t_st *b, t_list **lst)
{
	t_number	tmp;
	size_t		i;

	tmp = b->numbers[0];
	i = b->size;
	while (i--)
		swap_numbers(&(b->numbers[i]), &tmp);
	ft_lstadd_back(lst, ft_lstnew("rrb"));
}

void	pa(t_st *a, t_st *b, t_list **lst)
{
	if (!b->size)
		return ;
	a->numbers[a->size++] = b->numbers[b->size-- - 1];
	ft_lstadd_back(lst, ft_lstnew("pa"));
}

void	pb(t_st *a, t_st *b, t_list **lst)
{
	if (!a->size)
		return ;
	b->numbers[b->size++] = a->numbers[a->size-- - 1];
	ft_lstadd_back(lst, ft_lstnew("pb"));
}
