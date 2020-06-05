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
	char	*cmd;
	int		i;

	i = 0;
	while (get_next_line(0, &cmd))
	{
		if (ft_strcmp(cmd, "sa") && ft_strcmp(cmd, "sb") &&
		ft_strcmp(cmd, "ss") && ft_strcmp(cmd, "pa") && ft_strcmp(cmd, "pb")
		&& ft_strcmp(cmd, "ra") && ft_strcmp(cmd, "rb") && ft_strcmp(cmd, "rr")
		&& ft_strcmp(cmd, "rra") && ft_strcmp(cmd, "rrb") &&
		ft_strcmp(cmd, "rrr"))
		{
			ft_putstr("Error\n");
			free(cmd);
			return ;
		}
		else
			do_comand(a, b, cmd, 0);
		free(cmd);
	}
	free(cmd);
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
	b = make_stack(count, 0);
	if (!check_nums_in_stack(a))
		read_comands_write_result(a, b, count);
	free_stacks(&a, &b, &tab, argc);
	return (0);
}
