/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:58:53 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:58:54 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

int		check_str(char *str)
{
	int		flag;

	if (ft_strlen(str) - (*str == '-' || *str == '+') < 10)
		return (0);
	if (ft_strlen(str) - (*str == '-' || *str == '+') > 10)
		return (1);
	flag = *str == '-';
	str += flag || *str == '+';
	if (str[0] >= '2')
		if (str[1] >= '1')
			if (str[2] >= '4')
				if (str[3] >= '7')
					if (str[4] >= '4')
						if (str[5] >= '8')
							if (str[6] >= '3')
								if (str[7] >= '6')
									if (str[8] >= '4')
										if ((!flag && str[9] > '7')
										|| (flag && str[9] > '8'))
											return (1);
	return (0);
}

t_stack	*make_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = (t_stack*)malloc(sizeof(t_stack));
	a->nums = (int*)malloc(sizeof(int) * argc);
	a->stats = (signed char*)malloc(sizeof(signed char) * argc);
	a->size = argc;
	if (!argv)
		a->size = 0;
	i = 0;
	while (i++ < argc)
	{
		if (argv && check_str(argv[i - 1]))
		{
			free_stacks(&a, 0, 0, 0);
			write(2, "Error\n", 6);
			return (0);
		}
		if (!argv)
			a->nums[i - 1] = 0;
		else
			a->nums[i - 1] = ft_atoi(argv[i - 1]);
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
			{
				if ((j == 0 && !ft_isdigit(argv[i][j]) && argv[i][j] != '-' &&
				argv[i][j] != '+') || (j != 0 && !ft_isdigit(argv[i][j])) ||
				((argv[i][j] == '-' || argv[i][j] == '+') &&
				ft_strlen(argv[i]) == 1))
				{
					write(2, "Error\n", 6);
					return (0);
				}
				j++;
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
				write(2, "Error\n", 6);
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
		free((*a)->stats);
		free(*a);
	}
	if (b)
	{
		free((*b)->nums);
		free((*b)->stats);
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
