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

#include "includes/push_swap.h"

int		find_min(int *nums, int size)
{
	int		min;
	int		i;

	min = 0;
	i = 1;
	while (i < size)
	{
		if (nums[i] < nums[min])
			min = i;
		i++;
	}
	return (min);
}

int		do_long_list(t_stack *a, signed char **stats, int num)
{
	int		i;
	int		len;

	len = 1;
	i = 0;
	while (i < a->size)
		(*stats)[i++] = 0;
	(*stats)[num] = 1;
	i = num + 1;
	while (i < a->size)
	{
		if (a->nums[i] > a->nums[num])
		{
			(*stats)[i] = 1;
			len++;
			num = i;
		}
		i++;
	}
	return (len);
}

int		do_longest_list(t_stack *a, int old_len)
{
	int			i;
	int			j;
	signed char	*stats;
	int			len1;
	int			len;

	len = old_len;
	i = 0;
	while (i < a->size - len)
	{
		stats = malloc(sizeof(signed char) * a->size);
		if ((len1 = do_long_list(a, &stats, i++)) > len)
		{
			j = 0;
			while (j++ < a->size)
				a->stats[j - 1] = stats[j - 1];
			len = len1;
		}
		free(stats);
	}
	return (len);
}

int		check_status(signed char *stats, int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		if (!stats[i - 1])
			return (0);
	return (1);
}
