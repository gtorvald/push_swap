#include "includes/push_swap.h"

void	part_of_main_algorithm(t_stack *a, t_stack *b) {
	int		len;
	int		len1;

	len = do_longest_list(a, 0);
	while (!check_status(a->stats, a->size))
	{
		do_comand(a, b, "sa", 0);
		if ((len1 = do_longest_list(a, len)) <= len)
			do_comand(a, b, "sa", 0);
		else
		{
			ft_printf("sa\n");
			len = len1;
			continue ;
		}
		if (!a->stats[0])
			do_comand(a, b, "pb", 1);
		else
			do_comand(a, b, "ra", 1);
	}
}

void	do_main_algorithm(t_stack *a, t_stack *b)
{
	int		i;
	int		min;

	i = 0;
	while (i++ < a->size)
		a->stats[i] = 0;
	part_of_main_algorithm(a, b);
	while (b->size)
	{
		i = choose_element(a, b);
		prepare_stack_a(a, b->nums[i]);
		prepare_stack_b(b, i, 0);
		do_comand(a, b, "pa", 1);
	}
	min = find_min(a->nums, a->size);
	prepare_stack_b(a, min, 1);
}

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
	b = make_stack(count, 0);
	if (!check_nums_in_stack(a))
		do_main_algorithm(a, b);
	free_stacks(&a, &b, &tab, argc);
	return (0);
}
