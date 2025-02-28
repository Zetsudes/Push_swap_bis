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

int	get_nb_bits(unsigned int nb, int pos)
{
	return ((nb >> pos) & 1);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int len_stack;
	int pos;
	int i;

	len_stack = stack_size(*a);
	pos = 0;
	i = 0;

	while (!is_sorted(*a) && pos < 32)
		while (i < len_stack)
		{
			if (get_nb_bits((*a)->value, pos))
				rotate_a(a);
			else
				push_to_b(a, b);
			i++;
		}

	while (*b)
		push_to_a(a, b);

	pos++;
}
