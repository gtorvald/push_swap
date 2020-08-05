/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:58:36 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/23 16:58:38 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/printf.h"

int		check(char *str, char sym)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] == sym)
		{
			if (sym != '0')
				return (1);
			else if (i - 2 < 0 || (str[i - 2] < '0' || str[i - 2] > '9'))
				return (1);
		}
	return (0);
}

void	print_symbols(char symbol, int count)
{
	while (count-- > 0)
		ftb_putchar(symbol);
}
