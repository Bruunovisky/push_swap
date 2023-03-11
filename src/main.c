# include "push_swap.h"
# include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		result;
	void	*s;

	result = nmemb * size;
	if (result == 0 || result / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(result);
	s = ptr;
	while (result--)
		*(unsigned char *)s++ = 0;
	return (ptr);
}

void	print_stack(t_stack *node, int operations)
{
	while (node)
	{
		printf("%d\n", node->value);
		node = node->down;
	}
	printf("\nOperations: %d\n\n", operations);
}

int list_split(t_main *main, int range, int split)
{
	while (range && ++split)
		range /= 2;
	return (range = main->list_len / split);
}

void	define_groups(t_main *main)
{
	if (main->list_len > 5)
	{
		main->mid = ((main->value_max + main->value_min) / 2) + 1;
		main->top = find_group(main, main->mid - 1, 1);
		main->end = find_group(main, main->mid, -1);
	}
	else if (main->list_len <= 5)
    {
        main->end = main->value_min;
        main->mid = main->value_min;
        main->top = main->value_min;
    } 
}

int	main(int argc, char **argv)
{
	t_main	*main;

	main = (t_main *)ft_calloc(1, sizeof(t_main));
	main->list = (long *)ft_calloc(argc - 1, sizeof(long));
	main->value_max = INT_MIN;
	main->value_min = INT_MAX;
	main->list_len = argc - 1;
	main->stack_len = main->list_len;
	if (argc > 2)
	{
		main->range = list_split(main, main->list_len, 0);
		creat_stack(main, argc, argv);
		define_groups(main);
		sort(main);
	}
	free_main(main);
	return (EXIT_SUCCESS);
}
