#include "includes/push_swap.h"

int		steps_in_b(int size, int i)
{
	if (i > size - i)
		return (size - i);
	return(i + 1);
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
		if (i == 0)
			return (0);
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
			do_comand(a, 0, "rra");
	else
		while (j++ < steps)
			do_comand(a, 0, "ra");
}

void	prepare_stack_b(t_stack *b, int i)
{
	int		steps;
	int		j;

	steps = steps_in_b(b->size, i);
	j = 0;
	if (i > b->size - i)
		while (j++ < steps)
			do_comand(0, b, "rrb");
	else
		while (j++ < steps)
			do_comand(0, b, "rb");
}
