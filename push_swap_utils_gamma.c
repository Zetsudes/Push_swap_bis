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

int	stack_size(t_stack **stack)
{
	int	size;
	t_stack *tmp; 

	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
