/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:49:03 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:24:26 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap(t_stack *stack)
{
	t_stack *current = stack;
	int num;
	int tmp;

	num = 0;
	while (current)
	{
		num++;
		current = current->next;
	}
	if (num >= 2)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
	}
}

void	swap_a(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
