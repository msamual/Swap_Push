#include "push_swap.h"

void	sift_down(int *numbers, int root, int bottom)
{
	int	max_child;
	int	done;
	int	temp;

	done = 0;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			max_child = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;
		if (numbers[root] < numbers[max_child])
		{
			temp = numbers[root];
			numbers[root] = numbers[max_child];
			numbers[max_child] = temp;
			root = max_child;
		}
		else
			done = 1;
	}
}

void	heap_sort(int *numbers, int array_size)
{
	int	temp;
	int	i;

	i = array_size / 2;
	while (i >= 0)
		sift_down(numbers, i--, array_size - 1);
	i = array_size - 1;
	while (i >= 1)
	{
		temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		sift_down(numbers, 0, i - 1);
		i--;
	}
}

void	sort_array(int *arr, int size)
{
	heap_sort(arr, size);
}
