# include "push_swap.h"

void  free_main(t_main *main)
{
    while(main->stack_a_top && main->stack_a_end)
    {
        if (main->stack_a_top->up)
            free(main->stack_a_top->up);
        if (main->stack_a_end->down)
            free(main->stack_a_end->down);
        if (main->stack_a_top->down == main->stack_a_end)
        {
            free(main->stack_a_top);
            free(main->stack_a_end);
            break;
        }
        if (main->stack_a_top == main->stack_a_end)
        {
            free(main->stack_a_top);
            break;
        }
        main->stack_a_top = main->stack_a_top->down;
        main->stack_a_end = main->stack_a_end->up;
    }
    free(main->list);
	free(main);
}

void    error_free_exit(t_main *main)
{
	write(2, ERROR, 6);
    free_main(main);
	exit(EXIT_FAILURE);
}