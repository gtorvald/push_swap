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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUFF_SIZE 3
# define EOF (-1)

typedef struct		s_buff
{
	char			buff[BUFF_SIZE + 1];
	int				fd;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
