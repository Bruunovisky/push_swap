
# include "push_swap.h"

void    pushes(t_main *main)
{
    int value;

    if (main->set < 3)
    {
        push_b(main);
        value = main->stack_b_top->value;
        if (value < main->mid && main->stack_b_top->down) 
            main->rr = (value < main->stack_b_top->down->value);
    }
    else if (main->set == 3)
    {
        push_a(main);
        value = main->stack_a_top->value;
        main->rr += (value >= main->end);
        if (main->stack_a_top->value == main->top)
            main->top = list_search(main, main->top - 1, -1);
        if (main->stack_a_top->value == main->end)
            main->end = list_search(main, main->end + 1, 1);
    }
    main->stack_len += (main->set == 3) + -(main->set < 3);
}

void    swapses(t_main *main, t_stack *top_a)
{
    if (main->stack_len > 1 && main->stack_len <= 3)
    {
        if (top_a->value > top_a->down->value)
            swap(main, &main->stack_a_top, &main->stack_a_end, "sa");
    } 
}