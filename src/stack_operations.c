# include "push_swap.h"

void    push_a(t_main *main)
{
    if (main->stack_b_top == main->stack_b_end)
    {
        main->stack_a_top->up = main->stack_b_top;
        main->stack_b_top->down = main->stack_a_top;
        main->stack_a_top = main->stack_b_top;
        main->stack_b_top = NULL;
        main->stack_b_end = NULL;
    }
    else if (main->stack_a_top)
    {
        main->stack_a_top->up = main->stack_b_top;
        main->stack_b_top = main->stack_b_top->down;
        main->stack_b_top->up = NULL;
        main->stack_a_top->up->down = main->stack_a_top;
        main->stack_a_top = main->stack_a_top->up;
    }
    else if (!main->stack_a_top)
    {
        main->stack_a_top = main->stack_b_top;
        main->stack_a_end = main->stack_a_top;
        main->stack_b_top = main->stack_a_top->down;
        main->stack_a_top->down = NULL;
        main->stack_b_top->up = NULL;
    }
    write(1, "pa\n", 3);
    ++main->operations; 
}

void    push_b(t_main *main)
{
    if (main->stack_a_top == main->stack_a_end)
    {
        main->stack_b_top->up = main->stack_a_top;
        main->stack_a_top->down = main->stack_b_top;
        main->stack_b_top = main->stack_a_top;
        main->stack_a_top = NULL;
        main->stack_a_end = NULL;
    }
    else if (main->stack_b_top)
    {
        main->stack_b_top->up = main->stack_a_top;
        main->stack_a_top = main->stack_a_top->down;
        main->stack_a_top->up = NULL;
        main->stack_b_top->up->down = main->stack_b_top;
        main->stack_b_top = main->stack_b_top->up;
    }
    else if (!main->stack_b_top)
    {
        main->stack_b_top = main->stack_a_top;
        main->stack_b_end = main->stack_b_top;
        main->stack_a_top = main->stack_b_top->down;
        main->stack_b_top->down = NULL;
        main->stack_a_top->up = NULL;
    }
    write(1, "pb\n", 3);
    ++main->operations; 
}

void    swap(t_main *main, t_stack **top, t_stack **end, char *sa_sb_ss)
{
    if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 's')
    {
        ++main->operations;
        write(1, sa_sb_ss, 2);
        write(1, "\n", 1);   
        swap(main, &main->stack_a_top, &main->stack_a_end, "sa");
        return (swap(main, &main->stack_b_top, &main->stack_b_end, "sb"));
    }
    else
    {
        write(1, sa_sb_ss, 2);
        write(1, "\n", 1);
        ++main->operations;   
    } 
    (*top)->up = (*top)->down;
    if (!(*top)->down->down)
        *end = *top;
    if (!(*top)->down->down)
        (*end)->down = NULL;
    if ((*top)->down && (*top)->down->down)
        (*top)->down->down->up = *top;
    if ((*top)->down && (*top)->down->down)
        (*top)->down = (*top)->down->down;
    *top = (*top)->up;
    (*top)->down = (*top)->up;
    (*top)->up = NULL;
}

void    rotate(t_main *main, t_stack **top, t_stack **end, char *ra_rb_rr)
{
    if (ra_rb_rr[0] == 'r' && ra_rb_rr[1] == 'r')
    {
        ++main->operations;
        write(1, ra_rb_rr, 2);
        write(1, "\n", 1);
        rotate(main, &main->stack_a_top, &main->stack_a_end, " ");
        return (rotate(main, &main->stack_b_top, &main->stack_b_end, " "));
    }
    else if (ra_rb_rr[0] != ' ')
    {
        write(1, ra_rb_rr, 2);
        write(1, "\n", 1);
        ++main->operations;
    }
    (*end)->down = *top;
    (*top)->up = *end;
    *top = (*top)->down;
    *end = (*end)->down;
    (*end)->down = NULL;
    (*top)->up = NULL;
}

void    reverse_rotate(t_main *main, t_stack **top, t_stack **end, \
char *rra_rrb_rrr)
{
    if (rra_rrb_rrr[0] == 'r' && rra_rrb_rrr[1] == 'r' && rra_rrb_rrr[2] == 'r')
    {
        ++main->operations;
        write(1, rra_rrb_rrr, 3);
        write(1, "\n", 1);
        rotate(main, &main->stack_a_top, &main->stack_a_end, " ");
        return (rotate(main, &main->stack_b_top, &main->stack_b_end, " "));
    }
    else if (rra_rrb_rrr[0] != ' ')
    {
        write(1, rra_rrb_rrr, 3);
        write(1, "\n", 1);
        ++main->operations;
    }
    (*top)->up = *end;
    (*end)->down = *top;
    *end = (*end)->up;
    *top = (*top)->up;
    (*end)->down = NULL;
    (*top)->up = NULL;
}
