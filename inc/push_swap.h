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
    int     list_len;
    int     mid;
    int     operations;
    int     range;
    int     rr;
    int     set;
    int     stack_len;
    int     value_max;
    int     value_min;
    long    top;
    long    end;
    long    *list;
}   t_main;

void	*ft_calloc(size_t nmemb, size_t size);

void	creat_stack(t_main *main, int argc, char **argv, int *i);

void    error_free_exit(t_main *main);

void    push_a(t_main *main);

void    push_b(t_main *main);

void    sort(t_main *main);

void    swap(t_main *main, t_stack **top, t_stack **end, char *sa_sb_ss);

void    reverse_rotate(t_main *main, t_stack **top, t_stack **end, \
char *rra_rrb_rrr);

void    rotate(t_main *main, t_stack **top, t_stack **end, char *ra_rb_rr);

#endif