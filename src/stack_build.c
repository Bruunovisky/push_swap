# include "push_swap.h"

void    new_node(t_main *main, int value)
{
    t_stack *new_node;

    new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
    new_node->value = value;
    if (main->value_max < value)
        main->value_max = value;
    if (main->value_min > value)
        main->value_min = value;
    if (!main->stack_a_top)
    {
        main->stack_a_top = new_node;
        main->stack_a_end = new_node;
    }
    else
    {
        new_node->up = main->stack_a_end;
        new_node->up->down = new_node;
        main->stack_a_end = new_node;
    }
}

void    iter_nodes(t_main *main, int value)
{
    t_stack *tmp_top;
    t_stack *tmp_end;

    tmp_top = main->stack_a_top;
    tmp_end = main->stack_a_end;
    if (!tmp_top || (tmp_top && tmp_top == tmp_end && tmp_top->value != value))
        return (new_node(main, value));
    else if (tmp_top && tmp_end)
    {
        while (tmp_top->value != value && tmp_end->value != value)
        {
            if (tmp_top->down == tmp_end || tmp_end->up == tmp_top)
                return (new_node(main, value));
            if (tmp_top == tmp_end)
                return (new_node(main, value));
            tmp_top = tmp_top->down;
            tmp_end = tmp_end->up;
        }
    }
    error_free_exit(main);
}

void	creat_stack(t_main *main, int argc, char **argv, int *i)
{
    long value;
    int sign;

    i = (int *)ft_calloc(2, sizeof(int));
	while (++i[0] < argc)
	{
        value = 0;
        sign = 1;
		while (argv[i[0]][i[1]])
		{
            if (i[1] && (argv[i[0]][i[1]] < '0' || argv[i[0]][i[1]] > '9'))
                error_free_exit(main);
            else if (argv[i[0]][i[1]] == '-' && ++i[1])
                sign = -sign;
            else
            {
                value += (argv[i[0]][i[1]++] - 48) * sign;
                value += (argv[i[0]][i[1]] != '\0') * (value * 9);
            }
		}
        if (value > INT_MAX || value < INT_MIN)
            error_free_exit(main);
        iter_nodes(main, value);
        i[1] = 0;
	}
}
