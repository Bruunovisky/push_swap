# include "push_swap.h"

void    push(t_main *main, char *pa_pb)
{
    if (pa_pb[0] == 'p' && pa_pb[1] == 'a')
    {
        main->origin = main->stack_b_top;
        main->destine = main->stack_a_top;
        main->destine_end = main->stack_a_end;
    }
    else if (pa_pb[0] == 'p' && pa_pb[1] == 'b')
    {
        main->origin = main->stack_a_top;
        main->destine = main->stack_b_top;
        main->destine_end = main->stack_b_end;
    }
    if (main->destine)
        main->destine->up = main->origin;
    main->origin = main->origin->down;
    if (main->destine)
        main->origin->up->down = main->destine;
    main->destine = main->origin->up;
    main->origin->up = NULL;
    if (!main->destine_end)
    {
        main->destine->down = NULL;
        main->destine_end = main->destine;
    }
}

void    swap(t_main *main, char *sa_sb_ss)
{
    t_stack *target;

    if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 's')
    {
        swap(main, "sa");
        return (swap(main, "sb"));
    } 
    else if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 'a')
        target = main->stack_a_top;
    else if (sa_sb_ss[0] == 's' && sa_sb_ss[1] == 'b')
        target = main->stack_b_top;
    target->up = target->down;
    target->down = target->up->down;
    target->up->down = target;
    target = target->up;
    target->up = NULL;
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
        main->origin = main->stack_a_top;
        main->destine = main->stack_a_end;
    }
    else if (ra_rb_rr[0] == 'r' && ra_rb_rr[1] == 'b')
    {
        main->origin = main->stack_b_top;
        main->destine = main->stack_b_end;
    }
    main->destine->down = main->origin;
    main->origin->up = main->destine;
    main->origin = main->origin->down;
    main->destine = main->destine->down;
    main->destine->down = NULL;
    main->origin->up = NULL;
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
        main->origin = main->stack_a_end;
        main->destine = main->stack_a_top;
    }
    else if (rra_rrb_rrr[1] == 'r' && rra_rrb_rrr[2] == 'b')
    {
        main->origin = main->stack_b_end;
        main->destine = main->stack_b_top;
    }
    main->destine->up = main->origin;
    main->origin->down = main->destine;
    main->origin = main->origin->up;
    main->destine = main->destine->up;
    main->origin->down = NULL;
    main->destine->up = NULL;
}
