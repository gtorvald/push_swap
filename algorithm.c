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

int		steps_in_b(int size, int i)
{
	if (i > size - i)
		return (size - i);
	return (i);
}

int		steps_in_a(t_stack *a, int num)
{
	int		i;
	int		steps;

	i = 0;
	while (i < a->size && num < a->nums[i])
		i++;
	if (i == a->size)
		i = find_min(a->nums, a->size);
	else
	{
		i = 0;
		while (i < a->size && num > a->nums[i])
			i++;
		if (i == a->size)
			i = find_min(a->nums, a->size);
		else
			i = find_place(a->nums, a->size, num);
	}
	steps = i;
	if (i > a->size - i)
		steps = a->size - i;
	return (steps);
}

int		choose_element(t_stack *a, t_stack *b)
{
	int		i;
	int		index;
	int		step;
	int		step1;

	i = 0;
	index = 0;
	step = INT_MAX;
	while (i < b->size)
	{
		if ((step1 = steps_in_a(a, b->nums[i]) + steps_in_b(b->size, i)) < step)
		{
			index = i;
			step = step1;
		}
		i++;
	}
	return (index);
}

void	prepare_stack_a(t_stack *a, int num)
{
	int		i;
	int		j;

	i = 0;
	while (i < a->size && num < a->nums[i])
		i++;
	if (i == a->size)
		i = find_min(a->nums, a->size);
	else
	{
		i = 0;
		while (i < a->size && num > a->nums[i])
			i++;
		if (i == a->size)
			i = find_min(a->nums, a->size);
		else
			i = find_place(a->nums, a->size, num);
	}
	j = 0;
	if (i > a->size - i)
		while (j++ < a->size - i)
			do_comand(a, 0, "rra", 1);
	else
		while (j++ < i)
			do_comand(a, 0, "ra", 1);
}

void	prepare_stack_b(t_stack *b, int i, int flag)
{
	int		steps;
	int		j;

	steps = steps_in_b(b->size, i);
	j = 0;
	if (i > b->size - i)
		while (j++ < steps)
			if (flag)
				do_comand(b, 0, "rra", 1);
			else
				do_comand(0, b, "rrb", 1);
	else
		while (j++ < steps)
			if (flag)
				do_comand(b, 0, "ra", 1);
			else
				do_comand(0, b, "rb", 1);
}
