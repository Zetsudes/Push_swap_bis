/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
		+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
		+#+        */
/*                                                +#+#+#+#+#+
		+#+           */
/*   Created: 2025/01/14 09:49:40 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:14:40 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../greg_lib/libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAX_SIZE 100

typedef struct s_stack
{
	int value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

/* void	init_stack(Stack *s); */

void	push(t_stack **stack, t_stack **new);
void	push_to_a(t_stack **b, t_stack **a);
void	push_to_b(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);

int	get_nb_bits(unsigned int nb, int pos);
void	radix_sort(t_stack **a, t_stack **b);

void	swap(t_stack *stack);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_both(t_stack *a, t_stack *b);

void	rotate(t_stack **stack);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);

void	reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b);

void	sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
/* void	sort_big(t_stack *a, t_stack *b); */
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack *a, t_stack *b);

int	handle_error(void);
int	has_duplicate(t_stack *s, int num);
int	is_number(char *str);
int	is_sorted(t_stack *s);
/* int	find_median(t_stack *s); */

/* int	get_max(t_stack *stack); */
int	get_min(t_stack *stack);
int	get_pos(t_stack *stack, int num);
void	move_min_to_b(t_stack **a, t_stack **b);
/* int	get_rank(t_stack *a, int value); */
int	stack_size(t_stack *stack);

int	get_min_index(t_stack *a);

#endif
