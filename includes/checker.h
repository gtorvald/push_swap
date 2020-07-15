/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:58:53 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:58:54 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct	s_stack
{
	int			*nums;
	signed char	*stats;
	int			size;
}				t_stack;

void			free_stacks(t_stack **a, t_stack **b, char ***tab, int argc);
void			do_comand(t_stack *a, t_stack *b, char *comand, int flag);
int				check_str(char *str);
t_stack			*make_stack(int argc, char **argv);
t_stack			*check_and_make_stack(int argc, char **argv);
int				check_nums_in_stack(t_stack *a);

#endif
