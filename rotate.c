#include "push_swap.h"

void	rotate_loop(t_stack *a, int count, int com, t_list **lst)
{
	if (com == 0 || com == 2)
	{
		while (count--)
		{
			reverse_rotate_a(a, a);
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("rra")));
		}
	}
	else
	{
		while (count--)
		{
			rotate_a(a, a);
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("ra")));
		}
	}
}

void	push_all(t_stack *from, t_stack *to, char *com, t_list **lst)
{
	while (from->size)
	{
		push_a(to, from);
		ft_lstadd_back(lst, (void *)ft_lstnew(ft_strdup(com)));
	}	
}

void	push_and_rotate(t_stack *a, t_stack *b, t_stack *c, t_list **lst)
{
	push_b(a, b);
	ft_lstadd_back(lst, ft_lstnew(ft_strdup("pb")));
	if (b->numbers[b->size - 1] != c->numbers[c->size -1])
	{
		rotate_b(a, b);
		ft_lstadd_back(lst, ft_lstnew(ft_strdup("rb")));
		reverse_rotate_a(c, c);
	}
}

void	rotate_while(t_stack *stack, int x, t_list **lst, int side)
{
	if (side)
	{
		while (stack->numbers[stack->size - 1] != x)
		{
			rotate_a(stack, stack);
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("ra")));
		}
	}
	else
	{
		while (stack->numbers[stack->size - 1] != x)
		{
			reverse_rotate_a(stack, stack);
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("rra")));
		}
	}
}

void	turn_into_place(t_stack *a, int max, t_list **lst)
{
	size_t	i;

	i = a->size - 1;
	while (a->numbers[i] != max)
		i--;
	if (i > a->size - i)
		rotate_while(a, max, lst, 1);
	else
		rotate_while(a, max, lst, 0);
}
