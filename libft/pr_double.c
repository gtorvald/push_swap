/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:38:39 by gtorvald          #+#    #+#             */
/*   Updated: 2020/02/13 13:38:41 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*make_rounding(char **old_result, int i)
{
	int		j;
	char	*new_result;
	char	*result;

	j = i - 1;
	result = *old_result;
	while (result[j] == '9' || result[j] == '.')
		if (result[j--] != '.')
			result[j + 1] = '0';
	if (j != -1)
		result[j]++;
	else
	{
		new_result = malloc(sizeof(char) * (ft_strlen(result) + 2));
		new_result[0] = 1;
		ft_strcat(new_result + 1, result);
		free(result);
		return (new_result);
	}
	return (result);
}

char	*get_fractional_part(int precision, double num, char **number,
int sign)
{
	char	*result;
	int		i;
	int		prec;

	if (num < 0)
		num *= -1;
	i = ft_strlen(*number) + 1;
	result = malloc(i + 1 + precision);
	result[i + precision] = '\0';
	ft_strcpy(result, *number);
	free(*number);
	ft_strcat(result, ".");
	prec = precision;
	while (precision-- > 0)
	{
		num *= 10;
		result[i++] = (long long int)num % 10 + '0';
		if (precision == 0)
			if ((!sign && (long long int)(num * 10) % 10 > 4) ||
			(sign && (long long int)(num * 10) % 10 > 5) ||
			(sign && (long long int)(num * 10) % 10 > 4 && prec == 1))
				result = make_rounding(&result, i);
	}
	return (result);
}

char	*get_fractional_part_l(int precision, long double num, char **number,
int sign)
{
	char	*result;
	int		i;
	int		prec;

	if (num < 0)
		num *= -1;
	i = ft_strlen(*number) + 1;
	result = malloc(i + 1 + precision);
	result[i + precision] = '\0';
	ft_strcpy(result, *number);
	free(*number);
	ft_strcat(result, ".");
	prec = precision;
	while (precision-- > 0)
	{
		num *= 10;
		result[i++] = (long long int)num % 10 + '0';
		if (precision == 0)
			if ((!sign && (long long int)(num * 10) % 10 > 4) ||
			(sign && (long long int)(num * 10) % 10 > 5) ||
			(sign && (long long int)(num * 10) % 10 > 4 && prec == 1))
				result = make_rounding(&result, i);
	}
	return (result);
}

void	print_double(t_argument arg, va_list ap)
{
	double		num;
	char		*number;
	int			sign;
	int			rem;

	if (arg.precision == -1)
		arg.precision = 6;
	sign = 0;
	num = va_arg(ap, double);
	rem = (long long int)(num * 10) % 10;
	if (arg.precision == 0 && (rem > 4 || rem < -4))
	{
		if (num > 0)
			number = ft_itoa((long long int)num + 1);
		else
			number = ft_itoa((long long int)num - 1);
	}
	else
		number = ft_itoa((long long int)num);
	if (num < 0)
		sign = 1;
	num = num - (long long int)num;
	if (arg.precision != 0)
		number = get_fractional_part(arg.precision, num, &number, sign);
	print_flags_and_number_float(arg, &number, sign);
}

void	print_double_l(t_argument arg, va_list ap)
{
	long double	lnum;
	char		*number;
	int			sign;
	int			rem;

	if (arg.precision == -1)
		arg.precision = 6;
	sign = 0;
	lnum = va_arg(ap, long double);
	rem = (long long int)(lnum * 10) % 10;
	if (arg.precision == 0 && (rem > 4 || rem < -4))
	{
		if (lnum > 0)
			number = ft_itoa((long long int)lnum + 1);
		else
			number = ft_itoa((long long int)lnum - 1);
	}
	else
		number = ft_itoa((long long int)lnum);
	if (lnum < 0)
		sign = 1;
	lnum = lnum - (long long int)lnum;
	if (arg.precision != 0)
		number = get_fractional_part_l(arg.precision, lnum, &number, sign);
	print_flags_and_number_float(arg, &number, sign);
}
