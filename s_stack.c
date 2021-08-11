#include "push_swap.h"

t_st	*new_s_stack(void)
{
	t_st	*new;

	new = ft_calloc(1, sizeof(t_st));
	return (new);
}

void	push_nb(t_st *stack, t_number n)
{
	if (stack->size >= STACK_MAX_SIZE)
		exit(1);
	stack->numbers[stack->size] = n;
	stack->size++;
}

t_number	pop_nb(t_st *stack)
{
	if (stack->size < 1)
		exit(0);
	stack->size--;
	return (stack->numbers[stack->size]);
}

t_number	new_t_number(int n)
{
	t_number	number;

	number.n = n;
	number.already_sorted = 0;
	number.flag = 0;
	number.need = 0;
	return (number);
}
