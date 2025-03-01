/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:49:57 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:52:02 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int has_duplicate(t_stack *stack, int value) {
    t_stack *current = stack;
    
    while (current) {
        if (current->value == value)
            return 1;
        current = current->next;
    }
    return 0;
}

int is_sorted(t_stack **stack) {
    t_stack *current = *stack;
    
    while (current && current->next) {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}


int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/* int	find_median(t_stack *s)
{
	int tmp[s->top + 1];
	int i;
	int j;
	int temp;

	i = 0;
	while (i <= s->top)
	{
		tmp[i] = s->stack[i];
		i++;
	}
	i = 0;
	while (i < s->top)
	{
		j = 0;
		while (j < s->top - i)
		{
			if (tmp[j] > tmp[j + 1])
			{
				temp = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (tmp[(s->top) / 2]);
} */
