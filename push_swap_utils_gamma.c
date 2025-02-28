#include "push_swap.h"

int	get_min_index(t_stack *a)
{
	int	i;
	int	min_index;
	int	min_value;

	i = 0;
	min_index = 0;
	min_value = a->value;
	while (a)
	{
		if (a->value < min_value)
		{
			min_value = a->value;
			min_index = i;
		}
		i++;
		a = a->next;
	}
	return (min_index);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
