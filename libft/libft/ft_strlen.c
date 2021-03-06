/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:05:32 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/18 20:05:35 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (s[i++] != '\0')
		result++;
	return ((size_t)result);
}
