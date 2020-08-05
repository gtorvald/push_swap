/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:38:46 by gtorvald          #+#    #+#             */
/*   Updated: 2020/02/13 13:38:47 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	print_sign(t_argument arg, char *number, int sign)
{
	if (*number == '-' || sign)
		ftb_putchar('-');
	else if (check(arg.flags, '+'))
		ftb_putchar('+');
	else if (check(arg.flags, ' '))
		ftb_putchar(' ');
}

void	print_indentation_float(t_argument arg, char *number, int sign)
{
	if (check(arg.flags, '0'))
		print_symbols('0', arg.width - ft_strlen(number) - (*number != '-'
		&& (sign || check(arg.flags, '+') || check(arg.flags, ' '))));
	else
		print_symbols(' ', arg.width - ft_strlen(number) - (*number != '-'
		&& (sign || check(arg.flags, '+') || check(arg.flags, ' '))));
}

void	print_flags_and_number_float(t_argument arg, char **number, int sign)
{
	if (check(arg.flags, '-'))
		print_sign(arg, *number, sign);
	if (!check(arg.flags, '-'))
		print_indentation_float(arg, *number, sign);
	if (!check(arg.flags, '-'))
		print_sign(arg, *number, sign);
	ftb_putstr(*number + (**number == '-'));
	if (check(arg.flags, '-'))
		print_indentation_float(arg, *number, sign);
	if (check(arg.flags, '#') && arg.precision == 0)
		ftb_putchar('.');
	free(*number);
}
