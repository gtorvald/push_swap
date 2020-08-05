/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:47:57 by gtorvald          #+#    #+#             */
/*   Updated: 2019/12/22 21:47:58 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "libftbonus.h"

typedef struct	s_argumet
{
	char		type;
	char		*flags;
	int			width;
	int			precision;
	char		size;
}				t_argument;

int				g_count;

int				check(char *str, char sym);
void			print_symbols(char symbol, int count);

void			print_indentantion(t_argument argument, char *num);
void			print_alternative_form_frst(t_argument arg, char *num);
void			print_alternative_form_scnd(t_argument arg, char *num);
void			print_sign_of_number_frst(t_argument arg, char *num);
void			print_sign_of_number_scnd(t_argument arg, char *num);
void			print_flags_and_number(t_argument arg, char *num);
void			print_flags_and_number_float(t_argument arg, char **number,
int sign);

void			print_char(t_argument argument, va_list ap);
void			print_integer_number(t_argument *argument, va_list ap);
void			print_double(t_argument arg, va_list ap);
void			print_double_l(t_argument arg, va_list ap);

t_argument		get_info_about_argument(const char *format, va_list ap);
int				ft_printf(const char *restrict format, ...);

#endif
