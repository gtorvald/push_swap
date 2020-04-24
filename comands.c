#include "includes/get_next_line.h"
#include "includes/checker.h"

void	do_comand_sasb(t_stack *a, t_stack *b)
{
	int			num;
	signed char	stat;

	if (a->size < 3)
		return ;
	num = a->nums[1];
	stat = a->stats[1];
	a->nums[1] = a->nums[0];
	a->stats[1] = a->stats[0];
	a->nums[0] = num;
	a->stats[0] = stat;
	if (b)
		do_comand_sasb(b, 0);
}

void	do_comand_papb(t_stack *a, t_stack *b)
{
	int			num;
	signed char	stat;
	int			i;

	if (b->size == 0)
		return ;
	num = b->nums[0];
	stat = b->stats[0];
	i = 0;
	while (i++ < b->size - 1)
	{
		b->nums[i - 1] = b->nums[i];
		b->stats[i - 1] = b->stats[i];
	}
	b->size--;
	i = a->size;
	while (i-- > 0)
	{
		a->nums[i + 1] = a->nums[i];
		a->stats[i + 1] = a->stats[i];
	}
	a->nums[0] = num;
	a->stats[0] = stat;
	a->size++;
}

void	do_comand_rarb(t_stack *a, t_stack *b)
{
	int			num;
	signed char	stat;
	int			i;

	num = a->nums[0];
	stat = a->stats[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->nums[i] = a->nums[i + 1];
		a->stats[i] = a->stats[i + 1];
		i++;
	}
	a->nums[i] = num;
	a->stats[i] = stat;
	if (b)
		do_comand_rarb(b, 0);
}


void	do_comand_rrarrb(t_stack *a, t_stack *b)
{
	int			num;
	signed char	stat;
	int			i;

	if (a->size < 2)
		return ;
	num = a->nums[a->size - 1];
	stat = a->stats[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->nums[i] = a->nums[i - 1];
		a->stats[i] = a->stats[i - 1];
		i--;
	}
	a->nums[0] = num;
	a->stats[0] = stat;
	if (b)
		do_comand_rrarrb(b, 0);
}

void	do_comand(t_stack *a, t_stack *b, char *comand, int flag)
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
	if (flag)
		ft_printf("%s\n", comand);
}
