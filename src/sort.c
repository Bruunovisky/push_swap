# include "push_swap.h"

static t_stack *verify_stack(t_main *main, int ptr)
{
    if (main->set < 3 && !ptr)
        return (main->stack_a_top);
    else if (main->set < 3 && ptr)
        return (main->stack_a_end);
    else if (main->set == 3 && !ptr)
        return (main->stack_b_top);
    else if (main->set == 3 && ptr)
        return (main->stack_b_end);
    return (NULL);
}

int best_rotate(t_main *main, int min, int max)
{
    t_stack *top; 
    t_stack *end;
    int operations;

    operations = 0;

    top = verify_stack(main, 0);
    end = verify_stack(main, 1);
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

int list_search(t_main *main, long value, int direction)
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
            list_rev = list + main->list_len - 1;
            value += direction;
            continue;
        }
        list += 1;
        list_rev -= 1;
    }
    return (value);
}

static void sort_back(t_main *main)
{
    main->top = main->stack_a_top->value;
    main->top -= (main->stack_a_top->value > main->value_min);
    main->top = list_search(main, main->top, -1);
    main->end = main->stack_a_end->value; 
    main->end += (main->stack_a_end->value < main->value_max);
    main->end = list_search(main, main->end, 1);
    return (sort(main));
}

void    sort(t_main *main)
{   
    main->rr = 0;
    main->set += (main->set == 2);  
    while (!(main->set == 3 && main->stack_len == main->list_len))
    {  
        if (main->set < 3)
        {
            swapses(main, main->stack_a_top);
            main->set = stack_progress(main, main->stack_a_top, \
            main->stack_a_end);
        }
        if (main->set == 2)
            return(sort_back(main));       
        else if (main->set == 4)
            break;        
        rotations(main);
        pushes(main);
    }
    if (main->rr)
        rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
}
