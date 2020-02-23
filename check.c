#include "includes/checker.h"

int		check_str(char *str)
{
	int		flag;

	if (ft_strlen(str + (*str == '-')) < 10)
		return (0);
	if (ft_strlen(str + (*str == '-')) > 10)
		return (1);
	flag = *str == '-';
	str += flag;
	if (str[0] <= '2')
		if (str[1] <= '1')
			if (str[2] <= '4')
				if (str[3] <= '7')
					if (str[4] <= '4')
						if (str[5] <= '8')
							if (str[6] <= '3')
								if (str[7] <= '6')
									if (str[8] <= '4')
										if (str[9] <= '7'
										|| (flag && str[9] <= '8'))
											return (0);
	return (1);
}

t_stack	*make_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = (t_stack*) malloc(sizeof(t_stack));
	a->nums = (int*) malloc(sizeof(int) * argc);
	a->size = argc;
	if (!argv)
		a->size = 0;
	i = 0;
	while (i < argc)
	{
		if (argv && check_str(argv[i]))
		{
			free(a->nums);
			free(a);
			ft_putstr("Error\n");
			return (0);
		}
		if (!argv)
			a->nums[i] = 0;
		else
			a->nums[i] = ft_atoi(argv[i]);
		i++;
	}
	return (a);
}

t_stack	*check_and_make_stack(int argc, char **argv)
{
	int		i;
	int		j;

	if (argv)
	{
		i = 0;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
				if (!ft_isdigit(argv[i][j++]))
				{
					if (argv[i][j - 1] == '-' && j - 1 == 0)
						continue ;
					ft_putstr("Error\n");
					return (0);
				}
			i++;
		}
	}
	return (make_stack(argc, argv));
}

int		check_nums_in_stack(t_stack *a)
{
	int		i;
	int		j;

	i = 1;
	while (i < a->size)
	{
		j = 0;
		while (j < i)
			if (a->nums[i] == a->nums[j++])
			{
				ft_putstr("Error\n");
				return (1);
			}
		i++;
	}
	return (0);
}

void	free_stacks(t_stack **a, t_stack **b, char ***tab, int argc)
{
	int		i;

	if (a)
	{
		free((*a)->nums);
		free(*a);
	}
	if (b)
	{
		free((*b)->nums);
		free(*b);
	}
	if (argc == 2)
	{
		i = 0;
		while ((*tab)[i])
			free((*tab)[i++]);
		free((*tab)[i]);
		free(*tab);
	}
}
