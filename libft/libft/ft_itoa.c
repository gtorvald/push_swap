/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:04:00 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:04:01 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static char	*str(char **num, int n)
{
	if (n == -2147483648)
		ft_strcpy(*num, "-2147483648");
	else
		ft_strcpy(*num, "0");
	return (*num);
}

static int	get_size(int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*number;
	int		i;
	int		flag;
	int		size;

	size = get_size(n);
	if (!(number = malloc((size + 1) * sizeof(char))))
		return (NULL);
	number[size] = '\0';
	flag = 0;
	if (n == -2147483648 || n == 0)
		return (number = str(&number, n));
	if (n < 0)
		flag = 1;
	i = size - 1;
	while (n != 0)
	{
		number[i--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (flag)
		number[i] = '-';
	return (number);
}
