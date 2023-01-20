#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

#define ERROR "Error\n"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_stack
{
    int             value;
    struct s_stack  *up;
    struct s_stack  *down;
}   t_stack;

typedef struct s_main
{
    t_stack *stack_a_top;
    t_stack *stack_a_end;
    t_stack *stack_b_top;
    t_stack *stack_b_end;
    t_stack *origin;
    t_stack *destine;
    t_stack *destine_end;
    int     stack_half_a;
    int     stack_half_b;
    int     value_max;
    int     value_min;
    int     stack_top_size;
    int     stack_end_size;
}   t_main;

void	*ft_calloc(size_t nmemb, size_t size);

void	creat_stack(t_main *main, int argc, char **argv, int *i);

void    error_free_exit(t_main *main);

#endif