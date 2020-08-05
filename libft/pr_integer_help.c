/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:27:14 by gtorvald          #+#    #+#             */
/*   Updated: 2020/02/07 18:27:16 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	print_indentantion(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#')
		&& ft_strcmp(num, "0"))
		count += 2;
	if (arg.type == 'o' && check(arg.flags, '#') && ft_strcmp(num, "0"))
		count++;
	if (*num != '-' && check(arg.flags, '+'))
		count++;
	else if (*num != '-' && check("di", arg.type) && check(arg.flags, ' ')
		&& (arg.width <= count + 2 || check(arg.flags, '-')))
		count++;
	if (!ft_strcmp(num, "0") && arg.precision == 0 && arg.width > 0)
		count--;
	if (check(arg.flags, '0') && !check(arg.flags, '-') && arg.precision == -1)
		print_symbols('0', arg.width - count);
	else
		print_symbols(' ', arg.width - count);
}

void	print_alternative_form_frst(t_argument arg, char *num)
{
	if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
	(check(arg.flags, '-') || check(arg.flags, '0')) && ft_strcmp(num, "0"))
	{
		ftb_putchar('0');
		ftb_putchar(arg.type);
	}
	if (arg.type == 'o' && check(arg.flags, '#') && (check(arg.flags, '-')
		|| check(arg.flags, '0')) && ((ft_strcmp(num, "0"))
		|| (!ft_strcmp(num, "0") && arg.precision == 0)) &&
		((int)ft_strlen(num) > arg.precision))
		ftb_putchar('0');
}

void	print_alternative_form_scnd(t_argument arg, char *num)
{
	if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
	(!check(arg.flags, '-') && !check(arg.flags, '0')) &&
	ft_strcmp(num, "0"))
	{
		ftb_putchar('0');
		ftb_putchar(arg.type);
	}
	if (arg.type == 'o' && check(arg.flags, '#') && !check(arg.flags, '-')
	&& !check(arg.flags, '0') && ((ft_strcmp(num, "0"))
		|| (!ft_strcmp(num, "0") && arg.precision == 0)) &&
		((int)ft_strlen(num) > arg.precision))
		ftb_putchar('0');
}

void	print_sign_of_number_frst(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if (*num == '-')
	{
		if (check(arg.flags, '0') && arg.width > (int)ft_strlen(num)
		&& arg.precision == -1)
			ftb_putchar('-');
	}
	else if (check("di", arg.type) && check(arg.flags, '+') &&
		((check(arg.flags, '0') && arg.width > count) || arg.width <= count))
		ftb_putchar('+');
	else if (check("di", arg.type) && !check(arg.flags, '+')
	&& check(arg.flags, ' '))
		if (arg.width <= count + 2 || check(arg.flags, '-'))
			ftb_putchar(' ');
}

void	print_sign_of_number_scnd(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if (*num == '-')
		if (!check(arg.flags, '0') || arg.width <= (int)ft_strlen(num)
			|| arg.precision != -1)
			ftb_putchar('-');
	if (check("di", arg.type) && *num != '-' && check(arg.flags, '+') &&
		(!check(arg.flags, '0') || arg.width < count) && arg.width > count)
		ftb_putchar('+');
}
