#include "includes/get_next_line.h"
#include "includes/checker.h"

void	do_comand_sasb(t_stack *a, t_stack *b)
{
	int	num;

	if (a->size < 3)
		return ;
	num = a->nums[1];
	a->nums[1] = a->nums[0];
	a->nums[0] = num;
	if (b)
		do_comand_sasb(b, 0);
}

void	do_comand_papb(t_stack *a, t_stack *b)
{
	int	num;
	int	i;

	if (b->size == 0)
		return ;
	num = b->nums[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->nums[i] = b->nums[i + 1];
		i++;
	}
	b->size--;
	i = a->size;
	while (i > 0)
	{
		a->nums[i] = a->nums[i - 1];
		i--;
	}
	a->nums[0] = num;
	a->size++;
}

void	do_comand_rarb(t_stack *a, t_stack *b)
{
	int	num;
	int	i;

	num = a->nums[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->nums[i] = a->nums[i + 1];
		i++;
	}
	a->nums[i] = num;
	if (b)
		do_comand_rarb(b, 0);
}


void	do_comand_rrarrb(t_stack *a, t_stack *b)
{
	int	num;
	int	i;

	if (a->size < 2)
		return ;
	num = a->nums[a->size - 1];
	i = a->size;
	while (i > 0)
	{
		a->nums[i] = a->nums[i - 1];
		i--;
	}
	a->nums[0] = num;
	if (b)
		do_comand_rrarrb(b, 0);
}

int		do_comand(t_stack *a, t_stack *b, char *comand)
{
	if (!ft_strcmp(comand, "sa"))
		do_comand_sasb(a, 0);
	else if (!ft_strcmp(comand, "sb"))
		do_comand_sasb(b, 0);
	else if (!ft_strcmp(comand, "ss"))
		do_comand_sasb(a, b);
	else if (!ft_strcmp(comand, "pa"))
		do_comand_papb(a, b);
	else if (!ft_strcmp(comand, "pb"))
		do_comand_papb(b, a);
	else if (!ft_strcmp(comand, "ra"))
		do_comand_rarb(a, 0);
	else if (!ft_strcmp(comand, "rb"))
		do_comand_rarb(b, 0);
	else if (!ft_strcmp(comand, "rr"))
		do_comand_rarb(a, b);
	else if (!ft_strcmp(comand, "rra"))
		do_comand_rrarrb(a, 0);
	else if (!ft_strcmp(comand, "rrb"))
		do_comand_rrarrb(b, 0);
	else if (!ft_strcmp(comand, "rrr"))
		do_comand_rrarrb(a, b);
	else
		return (1);
	return (0);
}
