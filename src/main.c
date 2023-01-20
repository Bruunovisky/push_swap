# include "push_swap.h"

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

int main(int argc, char **argv)
{
    t_main  *main;

    main = (t_main *)ft_calloc(1, sizeof(t_main));
	main->stack_half_a = (argc - 1) / 2 + ((argc - 1) % 2 > 0);
	main->stack_half_b = (argc - 1) / 2;
	main->value_max = INT_MIN;
	main->value_min = INT_MAX;
    if (argc == 1)
		error_free_exit(main);
	if (argc == 2)
    	return (EXIT_SUCCESS);
	creat_stack(main, argc, argv, NULL);
	sort(main);
    return (EXIT_SUCCESS);
}
