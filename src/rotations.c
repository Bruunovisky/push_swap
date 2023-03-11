#include "push_swap.h"

int find_group(t_main *main, long value, int direction)
{
    int range;

    range = main->range;
    if (value != main->value_max || value != main->value_min)
    {
        while (range--)
        {
            value += direction;
            value = list_search(main, value, direction);
        }
    }
    if (value == main->value_max)
        return (list_search(main, value - 1, -1));
    return (value);
}

int optimize_cost(t_main *main, int min, int max)
{
    int cost;

    cost = best_rotate(main, min, max);
    while (max == main->top && cost == main->list_len)
    {
        main->top = find_group(main, main->top, 1);
        cost = best_rotate(main, main->mid, main->top);
        if (cost == main->list_len)
            break;
    }
    while (min == main->end && cost == main->list_len)
    {
        main->end = find_group(main, main->end, -1);
        cost = best_rotate(main, main->end, main->mid - 1);
        if (cost == main->list_len)
            break;
    }
    return (cost);
}

int     best_direction (t_main *main)
{
    int top_cost;
    int end_cost;
    int top_signal;
    int end_signal;
    int best_cost;

    top_signal = 1;
    end_signal = 1;
    if (main->set < 3)
        end_cost = optimize_cost(main, main->end, main->mid - 1);
    else if (main->set == 3)
        end_cost = best_rotate(main, main->end, main->end);
    end_signal *= -(end_cost < 0) + (end_cost >= 0);
    end_cost *= -(end_cost < 0) + (end_cost >= 0);
    if (main->set < 3)
        top_cost = optimize_cost(main, main->mid, main->top);
    else if (main->set == 3)
        top_cost = best_rotate(main, main->top, main->top);
    top_signal *= -(top_cost < 0) + (top_cost >= 0);
    top_cost *= -(top_cost < 0) + (top_cost >= 0);
    best_cost = (top_cost >= end_cost) * (end_cost * end_signal) + 
    (top_cost < end_cost) * (top_cost * top_signal);
    return (best_cost);
}

void    exec_rotations(t_main *main, int operation)
{
    while (operation)
    {
        if (operation > 0)
        {
            if (main->rr)
            {
                rotate(main, NULL, NULL, "rr");
                main->rr = 0;
            }
            else if (main->set < 3)
                rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
            else if (main->set == 3)
                rotate(main, &main->stack_b_top, &main->stack_b_end, "rb");
        }
        else if (operation < 0)
        {
            if (main->set < 3)
                reverse_rotate(main, &main->stack_a_top, \
                &main->stack_a_end, "rra");
            else if (main->set == 3)
                reverse_rotate(main, &main->stack_b_top, \
                &main->stack_b_end, "rrb");
        }
        operation += (operation < 0) + -(operation > 0);
    }
}

void    rotations(t_main *main)
{
    int operation;

    operation = best_direction(main);
    exec_rotations(main, operation);
    if (main->set < 3 && main->rr)
        rotate(main, &main->stack_b_top, &main->stack_b_end, "rb");
    else if (main->set == 3 && main->rr)
        rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
    main->rr = 0;
}