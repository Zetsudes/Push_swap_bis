/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:51:42 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 10:17:47 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort(t_stack *a, t_stack *b)
{
	int size;

	size = stack_size(a);
	if (is_sorted(a))
		return ;
	if (size == 2)
	{
		swap_a(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	if (size == 4)
	{
		sort_four(&a, &b);
		return ;
	}
	if (size == 5)
	{
		sort_five(a, b);
		return ;
	}
	radix_sort(&a, &b);
}

void	sort_three(t_stack *stack)
{
	int first;
	int second;
	int third;

	if (!stack || !stack->next || !stack->next->next)
		return ;
	first = stack->value;
	second = stack->next->value;
	third = stack->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(stack);
	else if (first > second && second > third)
	{
		swap_a(stack);
		reverse_rotate_a(&stack);
	}
	else if (first > second && second < third && first > third)
		rotate_a(&stack);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack);
		rotate_a(&stack);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(&stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;

	move_min_to_b(a, b);

	sort_three(*a);

	push_to_a(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	move_min_to_b(&a, &b);
	move_min_to_b(&a, &b);

	sort_three(a);

	push_to_a(&a, &b);
	push_to_a(&a, &b);
}

/* void	sort_big(Stack *a, Stack *b)
{
	if (a->top + 1 <= 100)
	{
		push_a_bit(a, b);
		push_back(a, b);
	}
	else
		radix_sort(a, b);
} */
