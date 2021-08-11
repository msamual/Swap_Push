#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_st	*stack_a;
	t_st	*stack_b;
	t_stack	*stack_c;

	stack_a = new_s_stack();
	stack_b = new_s_stack();
	stack_c = new_stack();
	i = ac;
	while (--i)
	{
		if (!is_number(av[i]))
			return (puterror("Error\n", 2));
		push_nb(stack_a, new_t_number(ft_atoi(av[i])));
		push(stack_c, ft_atoi(av[i]));
	}
	if (check_duplicates_s(stack_a))
		return (puterror("Error\n", 2));
	if (is_already_sorted(stack_a))
		return (0);
	sort_array(stack_c->numbers, stack_c->size);
	sorting(stack_a, stack_b, stack_c);
	return (0);
}
