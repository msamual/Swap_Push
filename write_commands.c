#include "push_swap.h"

void	write_commands(t_list *lst)
{
	while (lst)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

void	clear_list(t_list **lst)
{
	if (!((*lst)->next))
	{
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
	else
		clear_list(&((*lst)->next));
}

void	del(void *content)
{
	if (content)
		;
}

void	clear_all_list(t_list **lst)
{
	ft_lstclear(lst, del);
}
