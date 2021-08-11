#include "push_swap.h"

void	replace(char *str, t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next;
	lst->next = tmp->next;
	lst->content = str;
	free(tmp);
}

void	replace_two_with_one(char *cur, char *next, t_list *lst)
{
	if (!ft_strcmp(cur, "sa") && !ft_strcmp(next, "sb"))
		replace("ss", lst);
	else if (!ft_strcmp(cur, "sb") && !ft_strcmp(next, "sa"))
		replace("ss", lst);
	else if (!ft_strcmp(cur, "ra") && !ft_strcmp(next, "rb"))
		replace("rr", lst);
	else if (!ft_strcmp(cur, "rb") && !ft_strcmp(next, "ra"))
		replace("rr", lst);
	else if (!ft_strcmp(cur, "rra") && !ft_strcmp(next, "rrb"))
		replace("rrr", lst);
	else if (!ft_strcmp(cur, "rrb") && !ft_strcmp(next, "rra"))
		replace("rrr", lst);
}
