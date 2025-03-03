/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:49:32 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:49:51 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push(t_stack **stack, t_stack **new)
{
	t_stack *top;
	if (!stack || !*stack)
		return ;

	top = *stack;
	*stack = (*stack)->next;

	top->next = *new;
	*new = top;
}

void	push_to_a(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}