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

int     main(int argc, char **argv) 
{
    t_stack     *a;
    t_stack     *b;
    
    a = NULL;
    b = NULL;

    if (argc < 2)
        return 0;  
    if (!validate_and_push_args(argc, argv, &a))
        return handle_error();
    reverse_stack(&a);
    if (!is_sorted(&a))
        sort(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return 0;
}
