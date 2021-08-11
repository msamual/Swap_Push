#include "push_swap.h"

bool	to_be_removed(char *cur, char *next)
{
	if (!ft_strcmp(cur, "ra") && !ft_strcmp(next, "rra"))
		return (true);
	if (!ft_strcmp(cur, "rra") && !ft_strcmp(next, "ra"))
		return (true);
	if (!ft_strcmp(cur, "rb") && !ft_strcmp(next, "rrb"))
		return (true);
	if (!ft_strcmp(cur, "rrb") && !ft_strcmp(next, "rb"))
		return (true);
	if (!ft_strcmp(cur, "pa") && !ft_strcmp(next, "pb"))
		return (true);
	if (!ft_strcmp(cur, "pb") && !ft_strcmp(next, "pa"))
		return (true);
	return (false);
}

void	remove_from_begin(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst;
	tmp2 = (*lst)->next;
	*lst = tmp2->next;
	free(tmp1);
	free(tmp2);
}

void	remove_two_elem(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst->next;
	tmp2 = tmp1->next;
	lst->next = tmp2->next;
	free(tmp1);
	free(tmp2);
}

void	optimize_command_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*prev;
	char	*cur;
	char	*next;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	while ((*lst)->next && to_be_removed((*lst)->content,
			(*lst)->next->content))
		remove_from_begin(lst);
	tmp = *lst;
	while (tmp && tmp->next)
	{
		cur = tmp->content;
		next = tmp->next->content;
		if (to_be_removed(cur, next))
		{
			remove_two_elem(prev);
			optimize_command_list(lst);
			return ;
		}
		replace_two_with_one(cur, next, tmp);
		prev = tmp;
		tmp = tmp->next;
	}
}
