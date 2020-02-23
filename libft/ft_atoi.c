/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:52:48 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 13:52:50 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_res(const char *str, int i, int flag)
{
	int		result;
	int		count;

	if (!flag && ft_strlen(str + i) >= 19 &&
		(ft_strcmp(str + i, "9223372036854775807")) > 0)
		return (-1);
	if (flag && ft_strlen(str + i) >= 19 &&
		(ft_strcmp(str + i, "9223372036854775808") >= 0))
		return (0);
	result = 0;
	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		count++;
	}
	if (flag)
		result *= (-1);
	return (result);
}

static int	ft_check(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		flag;
	char	buf[9];

	ft_strcpy(buf, "\a\b\t\n\v\r\f ");
	flag = 0;
	i = 0;
	while (ft_check(buf, str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag = 1;
		if (!ft_strcmp(str, "-2147483648"))
			return (-2147483648);
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	return (get_res(str, i, flag));
}
