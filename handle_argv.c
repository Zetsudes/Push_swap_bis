#include "push_swap.h"

char    **split_input(int argc, char *arg)
{
    if (argc == 2)
        return (ft_split(arg, ' ')); 
    return (NULL);
}

int     handle_split_args(char **split_args, t_stack **a)
{
    int     i;
    
    i = 0;
    while (split_args[i]) {
        if (!validate_and_push(a, split_args[i])) {
            free_split_args(split_args);
            return (0);
        }
        i++;
    }
    free_split_args(split_args);
    return (1);
}

int     handle_individual_args(int argc, char **argv, t_stack **a)
{
    int     i;
    
    i = 1;
    while (i < argc) {
        if (!validate_and_push(a, argv[i]))
            return (0);
        i++;
    }
    return (1);
}

int     validate_and_push_args(int argc, char **argv, t_stack **a)
{
    char **split_args;
    
    split_args = split_input(argc, argv[1]);

    if (split_args)
        return (handle_split_args(split_args, a));
    else
        return (handle_individual_args(argc, argv, a));
}

int     validate_and_push(t_stack **a, char *arg)
{
    long    num;

    if (!validate_input(*a, arg))
        return 0;
    num = (long)ft_atoi(arg);
    return (push_node(a, (int)num));
}