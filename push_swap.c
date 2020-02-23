#include "includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;
	int		count;

	if (argc == 2)
	{
		count = count_str(argv[1], ' ');
		tab = ft_strsplit(argv[1], ' ');
	}
	else
	{
		count = argc - 1;
		tab = argv + 1;
	}
	if (argc == 1 || count == 0 || !(a = check_and_make_stack(count, tab)))
		return (1);
	free_stacks(0, 0, &tab, argc);
	b = make_stack(count, 0);
	if (!check_nums_in_stack(a))
		printf("rra\npb\nsa\nrra\npa\n");
	free_stacks(&a, &b, 0, 0);
	return (0);
}
