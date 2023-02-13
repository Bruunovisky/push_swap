# include "push_swap.h"
# include <stdio.h>

void	error_free_exit(t_main *main)
{
	write(2, ERROR, 6);
	free(main);
	exit(EXIT_FAILURE);
}

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

int main(int argc, char **argv)
{
    t_main  *main;

    main = (t_main *)ft_calloc(1, sizeof(t_main));
    main->list = (long *)ft_calloc(argc - 1, sizeof(long));
	main->value_max = INT_MIN;
	main->value_min = INT_MAX;
	main->list_len = argc - 1;
	main->stack_len = main->list_len;
	main->mid = main->list_len / 2;
	main->range = list_split(main, main->list_len, 0);
	main->top = (main->list_len / 2) + main->range;
	main->end = (main->list_len / 2) - main->range - 1;
    if (argc == 1)
		error_free_exit(main);
	if (argc == 2)
    	return (EXIT_SUCCESS);
	creat_stack(main, argc, argv, NULL);
	sort(main);
	print_stack(main->stack_a_top, main->operations);
    return (EXIT_SUCCESS);
}
