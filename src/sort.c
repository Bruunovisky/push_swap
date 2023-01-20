# include "push_swap.h"

void    sort(t_main *main)
{
    swap(main, "sa");
    push_b(main);
    push_b(main);
    push_b(main);
    rotate(main, "rr");
    reverse_rotate(main, "rrr");
    swap(main, "sa");
    push_a(main);
    push_a(main);
    push_a(main);
}