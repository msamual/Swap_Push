int	ft_int_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_int_max_three(int a, int b, int c)
{
	if (a > b > c)
		return (a);
	else if (b > a > c)
		return (b);
	else
		return (c);
}

void	swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}
