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

void    verify_duplicate(t_main *main, int value, int index)
{
    while(--index > -1)
    {
        if (main->list[index] == value)
            return(error_free_exit(main));
    }
    return (new_node(main, value));
}

void	creat_stack(t_main *main, int argc, char **argv)
{
    int sign;
    int i[2];

    i[0] = 0;
	while (++i[0] < argc)
	{
        sign = 1;
        i[1] = 0;
		while (argv[i[0]][i[1]])
		{
            if (argv[i[0]][i[1]] == '-' && ++i[1])
                sign = -sign;
            if (argv[i[0]][i[1]] < '0' || argv[i[0]][i[1]] > '9')
                error_free_exit(main);
            main->list[i[0] - 1] += (argv[i[0]][i[1]] - 48) * sign;
            main->list[i[0] - 1] += (argv[i[0]][i[1] + 1] != '\0') * \
            (main->list[i[0] - 1] * 9);
            ++i[1];
		}
        if (main->list[i[0] - 1] > INT_MAX || main->list[i[0] - 1] < INT_MIN)
            error_free_exit(main);
        verify_duplicate(main, main->list[i[0] - 1], i[0] - 1);
	}
}
