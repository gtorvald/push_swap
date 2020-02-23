/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:01:37 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:01:38 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			count_str(char const *s, char c)
{
	int		count;
	int		i;

	if (!s)
		return (-1);
	i = 1;
	if (s[0] == c || s[0] == '\0')
		count = 0;
	else
		count = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	size_str(const char *s, char c)
{
	int i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count;
	int		size;
	char	**tab;
	int		i;
	int		j;

	count = count_str(s, c);
	if (count == -1 || !(tab = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	tab[count] = NULL;
	i = 0;
	j = 0;
	while (i++ < count)
	{
		size = size_str(s + j, c);
		if (!(tab[i - 1] = (char*)malloc(size + 1)))
			return (NULL);
		tab[i - 1][size] = '\0';
		while (s[j] == c)
			j++;
		ft_strncpy(tab[i - 1], s + j, size);
		j += size;
	}
	return (tab);
}
