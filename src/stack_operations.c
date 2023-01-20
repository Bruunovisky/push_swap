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
}

void    swap(t_main *main, char *sa_sb_ss)
{
    if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 's')
    {
        swap(main, "sa");
        return (swap(main, "sb"));
    } 
    else if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 'a')
    {
        main->stack_a_top->up = main->stack_a_top->down;
        main->stack_a_top->down = main->stack_a_top->up->down;
        main->stack_a_top->down->up = main->stack_a_top;
        main->stack_a_top->up->down = main->stack_a_top;
        main->stack_a_top = main->stack_a_top->up;
        main->stack_a_top->up = NULL;
    }    
    else if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 'b')
    {
        main->stack_b_top->up = main->stack_b_top->down;
        main->stack_b_top->down = main->stack_b_top->up->down;
        main->stack_b_top->down->up = main->stack_b_top->up;
        main->stack_b_top->up->down = main->stack_b_top;
        main->stack_b_top = main->stack_b_top->up;
        main->stack_b_top->up = NULL;
    }
    write(1, sa_sb_ss, 2);
    write(1, "\n", 1);   
}

void    rotate(t_main *main, char *ra_rb_rr)
{
    if (ra_rb_rr[0] == 'r' && ra_rb_rr[1] == 'r')
    {
        rotate(main, "ra");
        return (rotate(main, "rb"));
    }
    else if (ra_rb_rr[0] == 'r' && ra_rb_rr[1] == 'a')
    {
        main->stack_a_end->down = main->stack_a_top;
        main->stack_a_top->up = main->stack_a_end;
        main->stack_a_top = main->stack_a_top->down;
        main->stack_a_end = main->stack_a_end->down;
        main->stack_a_end->down = NULL;
        main->stack_a_top->up = NULL;
    }
    else if (ra_rb_rr[0] == 'r' && ra_rb_rr[1] == 'b')
    {
        main->stack_b_end->down = main->stack_b_top;
        main->stack_b_top->up =main->stack_b_end;
        main->stack_b_top = main->stack_b_top->down;
        main->stack_b_end =main->stack_b_end->down;
        main->stack_b_end->down = NULL;
        main->stack_b_top->up = NULL;
    }
    write(1, ra_rb_rr, 2);
    write(1, "\n", 1);
}

void    reverse_rotate(t_main *main, char *rra_rrb_rrr)
{
    if (rra_rrb_rrr[0] == 'r' && rra_rrb_rrr[1] == 'r' && rra_rrb_rrr[2] == 'r')
    {
        rotate(main, "rra");
        return (rotate(main, "rrb"));
    }
    else if (rra_rrb_rrr[1] == 'r' && rra_rrb_rrr[2] == 'a')
    {
        main->stack_a_top->up = main->stack_a_end;
        main->stack_a_end->down = main->stack_a_top;
        main->stack_a_end = main->stack_a_end->up;
        main->stack_a_top = main->stack_a_top->up;
        main->stack_a_end->down = NULL;
        main->stack_a_top->up = NULL;
    write(1, "\n", 1);
    }
    else if (rra_rrb_rrr[1] == 'r' && rra_rrb_rrr[2] == 'b')
    {
        main->stack_b_top->up = main->stack_b_end;
        main->stack_b_end->down = main->stack_b_top;
        main->stack_b_end = main->stack_b_end->up;
        main->stack_b_top = main->stack_b_top->up;
        main->stack_b_end->down = NULL;
        main->stack_b_top->up = NULL;
    }
    write(1, rra_rrb_rrr, 3);
    write(1, "\n", 1);
}
