# include "push_swap.h"

int   best_rotate(t_main *main, int min, int max)
{
    t_stack *top; 
    t_stack *end;
    int operations;

    operations = 0;

    if (main->set < 3)
    {
        top = main->stack_a_top;
        end = main->stack_a_end;
    }
    else if (main->set == 3)
    {
        top = main->stack_b_top;
        end = main->stack_b_end;
    }
    while ((top->value < min || top->value > max) && \
    (end->value < min || end->value > max))
    {
        if (top->down == end || top == end)
            return (main->list_len);
        top = top->down;
        end = end->up;
        operations += 1;
    }
    if (top->value >= min && top->value <= max)
        return (operations);
    else if (end->value >= min && end->value <= max)
        return (-operations + -1);
    return (0);
}

void    stack_adjust(t_main *main, int value)
{
    while (value != main->stack_a_top->value)
    {
        if (best_rotate(main, value, value) > 0)
            rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
        else
            reverse_rotate(main, &main->stack_a_top, &main->stack_a_end, "rra");
    }
}

int     list_search(t_main *main, long value, int direction)
{
    long    *list;
    long    *list_rev;

    if ((value > main->value_max))
        return (main->value_max);
    if ((value < main->value_min))
        return (main->value_min);
    list = main->list;
    list_rev = list + main->list_len - 1;
    while (*list != value && *list_rev != value)
    {
        if (list == list_rev || list > list_rev)
        {
            list = main->list;
            list_rev = list + main->list_len;
            value += direction;
            continue;
        }
        list += 1;
        list_rev -= 1;
    }
    return (value);
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
    end_cost = best_rotate(main, main->end, main->mid - 1);
    while (end_cost == main->list_len)
    {
        main->end -= main->range;
        if (main->end < main->value_min) 
            main->end = main->value_min;
        end_cost = best_rotate(main, main->end, main->mid - 1);
        if (end_cost == main->list_len)
            break;
    }
    end_signal *= -(end_cost < 0) + (end_cost >= 0);
    end_cost *= -(end_cost < 0) + (end_cost >= 0);
    top_cost = best_rotate(main, main->mid, main->top);
    while (top_cost == main->list_len)
    {
        main->top += main->range;
        if (main->top > main->value_max)
            main->top = main->value_max;
        top_cost = best_rotate(main, main->mid, main->top);
        if (top_cost == main->list_len)
            break;
    }
    top_signal *= -(top_cost < 0) + (top_cost >= 0);
    top_cost *= -(top_cost < 0) + (top_cost >= 0);
    best_cost = (top_cost >= end_cost) * (end_cost * end_signal) + 
    (top_cost < end_cost) * (top_cost * top_signal);
    return (best_cost);
}

int   stack_a_progress(t_main *main, t_stack *top, t_stack *end)
{
    long    top_next;
    long    end_next;

    top_next = list_search(main, top->value + 1, 1);
    end_next = list_search(main, end->value - 1, -1);
    while ((top->down && top->down->value == top_next) || \
    (end->up && end->up->value == end_next))
    {
        if (top == end || top->up == end)
        {
            if (main->stack_len < main->list_len)
                break;
            else
                return (4);
        }
        if (top->down->value == top_next)
            top = top->down;
        if (top->value == top_next)
            top_next = list_search(main, top_next + 1, 1);
        if (end->up->value == end_next)
            end = end->up;
        if (end->value == end_next)
            end_next = list_search(main, end_next - 1, -1);   
    }
    if ((top->down == NULL && end->up == NULL && end->value == end_next) || \
   ((top == end || top->up == end) && (main->stack_len < main->list_len)) || \
    main->stack_len == 1)
    {
        if (main->rr)
            rotate(main, &main->stack_b_top, &main->stack_b_end, "rb");
        return (2);
    }
    if ((top != main->stack_a_top && top->down == end) || \
    (top->down == NULL && end->up == NULL && end->value == end_next))
    {
        stack_adjust(main, top->down->value);
        return (1);
    }
    return (0);
}

void    pushes(t_main *main)
{
    int value;
    int value_down;

    value_down = main->value_max;
    if (main->set < 3)
    {
        push_b(main);
        value = main->stack_b_top->value;
        if (main->stack_b_top->down)
            value_down = main->stack_b_top->down->value;
    }
    else if (main->set == 3)
    {
        push_a(main);
        value = main->stack_a_top->value;
    }
    if (main->set < 3 && value < value_down)
        main->rr += (value <= main->mid && value >= main->end);
    if (main->set == 3)
        main->rr += (value >= main->end);
    main->stack_len += (main->set == 3) + -(main->set < 3);
    main->top -= (main->stack_a_top->value == main->top);
    main->end += (main->stack_a_top->value == main->end);
}

void    rotations(t_main *main)
{
    int operation;


    if (main->set < 3)
        operation = best_direction(main);
    if (main->set == 3)
        operation = best_rotate(main, main->top, main->end);
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
    if (main->set < 3 && main->rr)
        rotate(main, &main->stack_b_top, &main->stack_b_end, "rb");
    else if (main->set == 3 && main->rr)
        rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
    main->rr = 0;
}

void    sort(t_main *main)
{   
    main->rr = 0;
    main->set += (main->set == 2);
    while (!(main->set == 3 && main->stack_len == main->list_len))
    {  
        if (main->set < 3 && main->stack_len > 1 && main->stack_len <= 3 && \
        main->stack_a_top->value > main->stack_a_top->down->value)
            swap(main, &main->stack_a_top, &main->stack_a_end, "sa");
        if (main->set != 3)
            main->set = stack_a_progress(main, main->stack_a_top, \
            main->stack_a_end);
        if (main->set == 2)
        {
            main->top = main->stack_a_top->value;
            main->top -= (main->stack_a_top->value > main->value_min);
            main->top = list_search(main, main->top, -1);
            main->end = main->stack_a_end->value; 
            main->end += (main->stack_a_end->value < main->value_max);
            main->end = list_search(main, main->end, 1);
            return (sort(main));
        }
        else if (main->set == 1)
            continue;         
        else if (main->set == 4)
            break;        
        rotations(main);
        pushes(main);
    }
    if (main->rr)
        rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
}
