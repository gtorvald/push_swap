/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftb_putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:38:24 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/25 20:38:27 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

int		ftb_putchar(unsigned char c)
{
	g_count++;
	return (write(1, &c, 1));
}
