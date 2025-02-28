/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:49:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 14:11:36 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	free_split_args(char **args)
{
	int i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	validate_and_push(t_stack *a, char *arg)
{
	long num;
	t_stack *new_node;

	if (!is_number(arg))
		return (0);
	num = (long)ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (has_duplicate(a, (int)num))
		return (0);

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);

	new_node->value = (int)num;
	new_node->next = NULL;
	new_node->prev = NULL;

	push(&a, &new_node);
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack *temp;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int i;
	char **split_args;

	if (argc < 2)
		return (handle_error());

	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			return (handle_error());

		i = 0;
		while (split_args[i])
		{
			if (!validate_and_push(a, split_args[i]))
			{
				free_split_args(split_args);
				free_stack(&a);
				return (handle_error());
			}
			i++;
		}
		free_split_args(split_args);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!validate_and_push(a, argv[i]))
			{
				free_stack(&a);
				return (handle_error());
			}
			i++;
		}
	}

	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}

	sort(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
