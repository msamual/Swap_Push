#include "libft.h"

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->size = 0;
	return (stack);
}
