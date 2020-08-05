/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftb_nputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:06:24 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/25 22:06:26 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

void	ftb_nputstr(char *str, int n)
{
	if (!ft_strcmp(str, "%"))
	{
		ftb_putchar('%');
		return ;
	}
	while (*str != '\0' && n > 0)
	{
		ftb_putchar(*str);
		str++;
		n--;
	}
}
