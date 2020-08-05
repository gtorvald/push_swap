/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:37:24 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/23 17:37:33 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	print_string(t_argument argument, char *string)
{
	int		len;

	if (!string)
	{
		string = malloc(sizeof(char) * 7);
		ft_strcpy(string, "(null)\0");
	}
	len = ft_strlen(string);
	if (argument.precision != -1 && len > argument.precision)
		len = argument.precision;
	if (!check(argument.flags, '-'))
		while (argument.width-- - len > 0)
			ftb_putchar(' ');
	if (argument.precision != -1 && argument.type == 's')
		ftb_nputstr(string, argument.precision);
	else if (argument.type == 'c' && !ft_strcmp(string, ""))
		ftb_putchar(0);
	else
		ftb_putstr(string);
	while (argument.width-- - len > 0)
		ftb_putchar(' ');
	if (!ft_strcmp(string, "(null)"))
		free(string);
}

void	print_char(t_argument argument, va_list ap)
{
	char	*string;

	if (argument.type != 's')
	{
		string = malloc(2 * sizeof(char));
		string[1] = '\0';
		if (argument.type == '%')
			string[0] = '%';
		else
			string[0] = (char)va_arg(ap, int);
		if (!ft_strcmp(string, "") && argument.width > 0)
			argument.width--;
		print_string(argument, string);
		free(string);
	}
	else
		print_string(argument, va_arg(ap, char*));
}
