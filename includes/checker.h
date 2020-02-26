#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_stack
{
	int			*nums;
	signed char	*stats;
	int			size;
}				t_stack;

void			free_stacks(t_stack **a, t_stack **b, char ***tab, int argc);
int				do_comand(t_stack *a, t_stack *b, char *comand, int flag);
int				check_str(char *str);
t_stack			*make_stack(int argc, char **argv);
t_stack			*check_and_make_stack(int argc, char **argv);
int				check_nums_in_stack(t_stack *a);

#endif
