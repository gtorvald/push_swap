/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:00:46 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:00:48 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < (int)n)
		i++;
	if (i == (int)n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
