/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/24 14:05:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:19 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	get_max(t_stack *stack) 
{
    int max;
	
	max = stack->value;
    while (stack) {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

int		get_min(t_stack *stack)
{
	int min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int		get_pos(t_stack *stack, int num)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == num)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
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

void	move_min_to_b(t_stack **a, t_stack **b)
{
	int min;
	int pos;
	int size;

	if (!a || !*a)
		return ;
	min = get_min(*a);
	pos = get_pos(*a, min);
	size = stack_size(a);
	if (pos <= size / 2)
	{
		while (*a && (*a)->value != min)
			rotate_a(a);
	}
	else
	{
		while (*a && (*a)->value != min) 
			reverse_rotate_a(a);
	}
	push_to_b(a, b); 
}