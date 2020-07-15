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

int		find_place(int *nums, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			if (nums[size - 1] < num && nums[0] > num)
				break ;
		}
		else if (nums[i - 1] < num && nums[i] > num)
			break ;
		i++;
	}
	return (i);
}

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

int		get_stats(int *p, int *d, t_stack *a, int old_len)
{
	int i;
	int max;
	int max_index;

	i = 0;
	max = 0;
	max_index = 0;
	while (i < a->size)
		if (p[i++] > max)
		{
			max = p[i - 1];
			max_index = i - 1;
		}
	if (max <= old_len)
		return (max);
	i = 0;
	while (i < a->size)
		a->stats[i++] = 0;
	while (max_index != -1)
	{
		a->stats[max_index] = 1;
		max_index = d[max_index];
	}
	return (max);
}

int		do_longest_list(t_stack *a, int old_len)
{
	int	p[a->size];
	int	d[a->size];
	int i;
	int j;

	i = 0;
	while (i < a->size)
	{
		d[i] = -1;
		p[i] = 1;
		j = 0;
		while (j < i)
			if (a->nums[j++] < a->nums[i] && 1 + p[j - 1] > p[i])
			{
				p[i] = p[j - 1] + 1;
				d[i] = j - 1;
			}
		i++;
	}
	return (get_stats(p, d, a, old_len));
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
