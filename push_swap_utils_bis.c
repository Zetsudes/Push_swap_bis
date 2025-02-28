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


/* int	get_max(t_stack *stack)
{
	int max;
	int i;

	i = 0;
	max = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
} */

int	get_min(t_stack *stack)
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

int	get_pos(t_stack *stack, int num)
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

void	move_min_to_b(t_stack **a, t_stack **b)
{
	int min;
	int pos;
	int size;

	if (!a || !*a) // Ensure `a` is valid
		return ;

	min = get_min(*a);
	pos = get_pos(*a, min);
	size = stack_size(*a);

	if (pos <= size / 2)
	{
		while (*a && (*a)->value != min) // Prevent accessing NULL
			rotate_a(a);
	}
	else
	{
		while (*a && (*a)->value != min) // Prevent accessing NULL
			reverse_rotate_a(a);
	}
	push_to_b(a, b); // Push from A to B
}

/* int	get_rank(t_stack *a, int value)
{
	int i;
	int rank;

	rank = 0;
	i = 0;
	while (i <= a->top)
	{
		if (a->stack[i] < value)
			rank++;
		i++;
	}
	return (rank);
} */
