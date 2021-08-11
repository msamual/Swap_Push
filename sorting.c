#include "push_swap.h"

void	sort_three(t_st *a, t_list **lst)
{
	int	n0;
	int	n1;
	int	n2;

	n0 = a->numbers[0].n;
	n1 = a->numbers[1].n;
	n2 = a->numbers[2].n;
	if (n0 < n1 && n1 < n2)
	{
		ra(a, lst);
		sa(a, lst);
	}
	else if (n0 > n1 && n1 < n2 && n0 > n2)
		sa(a, lst);
	else if (n0 > n1 && n1 < n2 && n0 < n2)
		ra(a, lst);
	else if (n0 < n1 && n1 > n2 && n0 > n2)
	{
		sa(a, lst);
		ra(a, lst);
	}
	else
		rra(a, lst);
}

void	sort_three_elements(t_st *a, t_list **lst)
{
	if (a->size < 2)
		return ;
	else if (a->size == 2 && a->numbers[1].n > a->numbers[0].n)
		sa(a, lst);
	else
		sort_three(a, lst);
}

void	sort_five_elements(t_st *a, t_st *b, t_list **lst)
{
	while (a->size > 3)
		pb(a, b, lst);
	sort_three_elements(a, lst);
	while (b->size && a->size < 5)
		insert_number_to_place(a, b, lst);
}

void	sorting(t_st *a, t_st *b, t_stack *c)
{
	t_list	*command_list;

	a->expected = 0;
	b->expected = 0;
	command_list = NULL;
	if (a->size < 4)
		sort_three_elements(a, &command_list);
	else if (a->size < 6)
		sort_five_elements(a, b, &command_list);
	else
		sort_all(a, b, c, &command_list);
	turn_in_place(a, c->numbers[0], &command_list);
	optimize_command_list(&command_list);
	ft_lstiter(command_list, ft_putendl_void);
	clear_all_list(&command_list);
	free(a);
	free(b);
}
