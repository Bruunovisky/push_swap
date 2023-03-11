#include "push_swap.h"

static void	stack_adjust(t_main *main, int value)
{
	while (value != main->stack_a_top->value)
	{
		if (best_rotate(main, value, value) > 0)
			rotate(main, &main->stack_a_top, &main->stack_a_end, "ra");
		else
			reverse_rotate(main, &main->stack_a_top, &main->stack_a_end, "rra");
	}
	main->set = 1;
}

static int	stack_shift(t_main *main, t_stack *top, t_stack *end, long end_next)
{
	if ((top->down == NULL && end->up == NULL && end->value == end_next) || \
	((top == end || top->up == end) && (main->stack_len < main->list_len)) || \
	main->stack_len == 1)
	{
		if (main->rr)
			rotate(main, &main->stack_b_top, &main->stack_b_end, "rb");
		return (2);
	}
	if (!main->set && ((top != main->stack_a_top && top->down == end) || \
	(top->down == NULL && end->up == NULL && end->value == end_next)))
	{
		stack_adjust(main, top->down->value);
		return (stack_progress(main, main->stack_a_top, main->stack_a_end));
	}
	return (0);
}

int	stack_progress(t_main *main, t_stack *top, t_stack *end)
{
	long	top_next;
	long	end_next;

	top_next = list_search(main, top->value + 1, 1);
	end_next = list_search(main, end->value - 1, -1);
	while ((top->down && top->down->value == top_next) || \
	(end->up && end->up->value == end_next))
	{
		if (top == end || top->up == end)
		{
			if (main->stack_len < main->list_len)
				return (stack_shift(main, top, end, end_next));
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
	return (stack_shift(main, top, end, end_next));
}