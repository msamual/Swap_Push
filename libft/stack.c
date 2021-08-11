#include "libft.h"

void	push(t_stack *stack, int n)
{
	if (stack->size >= STACK_MAX_SIZE)
		exit(1);
	stack->numbers[stack->size] = n;
	stack->size++;
}

int	pop(t_stack *stack)
{
	if (stack->size < 1)
		exit(0);
	stack->size--;
	return (stack->numbers[stack->size]);
}

void	print_three_stacks(t_stack *a, t_stack *b, t_stack *c)
{
	size_t	i;

	i = ft_int_max_three(a->size, b->size, c->size);
	while (i--)
	{
		if (a->size > i)
			printf("%-20d", a->numbers[i]);
		else
			printf("                    ");
		if (b->size > i)
			printf("%-20d", b->numbers[i]);
		else
			printf("                    ");
		if (c->size > i)
			printf("%d\n", c->numbers[i]);
		else
			printf("\n");
	}
	printf("size = %-13zusize = %zu\n", a->size, b->size);
	write (1, "----------------------------------------\n", 31);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	size_t	i;

	i = ft_int_max(a->size, b->size);
	while (i--)
	{
		if (a->size > i)
			printf("%-20d", a->numbers[i]);
		else
			printf("                    ");
		if (b->size > i)
			printf("%d\n", b->numbers[i]);
		else
			printf("\n");
	}
	printf("size = %-13zusize = %zu\n", a->size, b->size);
	write (1, "------------------------------\n", 31);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->size;
	while (i-- > 0)
	{
		ft_putnbr_fd(stack->numbers[i], 1);
		write(1, "\n", 1);
	}
	write(1, "size = ", 7);
	ft_putnbr_fd(stack->size, 1);
	write(1, "\n", 1);
}
