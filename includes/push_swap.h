#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

int		choose_element(t_stack *a, t_stack *b);
void	prepare_stack_a(t_stack *a, int num);
void	prepare_stack_b(t_stack *b, int i, int flag);
int		find_min(int *nums, int size);
int		check_status(signed char *stats, int size);
int		do_longest_list(t_stack *a, int old_len);

#endif
