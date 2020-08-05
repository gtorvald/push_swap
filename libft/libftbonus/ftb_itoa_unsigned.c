/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:11:23 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/25 18:11:25 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static char	*str(char **num)
{
	ft_strcpy(*num, "0");
	return (*num);
}

static int	get_size(unsigned long long int n, int system)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= system;
	}
	return (size);
}

char		*ft_itoa_un(unsigned long long int n, int system)
{
	char	*number;
	int		i;
	int		size;

	size = get_size(n, system);
	if (!(number = malloc((size + 1) * sizeof(char))))
		return (NULL);
	number[size] = '\0';
	if (n == 0)
		return (number = str(&number));
	i = size - 1;
	while (n != 0)
	{
		if (system != 16)
			number[i--] = n % system + '0';
		else
		{
			if (n % 16 < 10)
				number[i--] = n % 16 + '0';
			else
				number[i--] = n % 16 + 'a' - 10;
		}
		n /= system;
	}
	return (number);
}
