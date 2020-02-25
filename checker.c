#include "includes/checker.h"
#include <stdio.h>

int		check_nums(t_stack *a, t_stack *b, int count)
{
	int		i;

	if (a->size != count || b->size != 0)
		return (1);
	i = 1;
	while (i < a->size)
	{
		if (a->nums[i] < a->nums[i - 1])
			return (1);
		i++;
	}
	return (0);
}

void	read_comands_write_result(t_stack *a, t_stack *b, int count)
{
	char	*comand;

	comand = NULL;
	while (get_next_line(0, &comand))
	{
		if (do_comand(a, b, comand))
		{
			ft_putstr("Error\n");
			free(comand);
			return ;
		}
	}
	if (comand)
		free(comand);
	if (check_nums(a, b, count))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
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
	free_stacks(0, 0, &tab, argc);
	b = make_stack(count, 0);
	if (!check_nums_in_stack(a))
		read_comands_write_result(a, b, count);
	free_stacks(&a, &b, 0, 0);
	return (0);
}
