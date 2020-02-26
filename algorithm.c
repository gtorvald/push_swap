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

int		steps_in_b(int size, int i)
{
	if (i > size - i)
		return (size - i);
	return(i);
}

int		steps_in_a(t_stack *a, int num)
{
	int		i;
	int		steps;

	if (a->nums[0] > num)
	{
		i = a->size - 1;
		while (a->nums[i] > num && i >= 0)
			i--;
		if (i == -1)
			return (find_min(a->nums, a->size));
	}
	else
	{
		i = 0;
		while (a->nums[i] < num)
			i++;
		i--;
	}
	steps = i + 1;
	if (i + 1 > a->size - i - 1)
		steps = a->size - i - 1;
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
	step = b->size;
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
	int		steps;
	int		j;
	
	if (a->nums[0] > num)
	{
		i = a->size - 1;
		while (a->nums[i] > num)
			i--;
	}
	else
	{
		i = 0;
		while (a->nums[i] < num)
			i++;
		i--;
	}
	j = 0;
	steps = steps_in_a(a, num);
	if (i + 1 > a->size - i - 1)
		while (j++ < steps)
			do_comand(a, 0, "rra", 1);
	else
		while (j++ < steps)
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
