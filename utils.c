#include "push_swap.h"

int		get_nb_bits(unsigned int nb, int pos)
{
	return ((nb >> pos) & 1);
}

void 	free_split_args(char **args) 
{
    int     i;
    
    i = 0;
    while (args[i]) {
        free(args[i]);
        i++;
    }
    free(args);
}

void    free_stack(t_stack **stack) 
{
    t_stack     *temp;

    while (*stack) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

void    reverse_stack(t_stack **stack) {

    t_stack     *current;
    t_stack     *temp;
  
    current = *stack;
    temp = NULL;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp)
        *stack = temp->prev;
}

int 	push_node(t_stack **a, int num)
{
    t_stack 	*new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (0);
    new_node->value = num;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*a == NULL) 
        *a = new_node;
    else 
	{
        new_node->next = *a;
        (*a)->prev = new_node;
        *a = new_node;
    }
    return (1);
}
