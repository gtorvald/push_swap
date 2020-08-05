/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:58:48 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:58:50 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void			ft_lstcreat(t_buff **buf, int fd, char *str)
{
	t_buff	*help;

	help = *buf;
	if (!help)
	{
		*buf = malloc(sizeof(t_buff));
		ft_strcpy((*buf)->buff, str);
		(*buf)->fd = fd;
		(*buf)->next = NULL;
		return ;
	}
	while (help->next)
		help = help->next;
	help->next = malloc(sizeof(t_buff));
	ft_strcpy(help->next->buff, str);
	help->next->fd = fd;
	help->next->next = NULL;
}

void			ft_lstdelet(t_buff **buf, int fd)
{
	t_buff	*help;
	t_buff	*del;

	help = *buf;
	if (help->fd == fd)
	{
		*buf = (*buf)->next;
		if (help)
			free(help);
		return ;
	}
	while (help->next->fd != fd)
		help = help->next;
	del = help->next;
	help->next = del->next;
	if (del)
		free(del);
}

int				out_buff(const int fd, char **line, t_buff **g_buff)
{
	t_buff	*help;
	int		i;
	char	copy[BUFF_SIZE];
	char	c;

	help = *g_buff;
	while (help)
	{
		if (help->fd == fd)
			break ;
		help = help->next;
	}
	i = 0;
	while (help && (c = help->buff[i]) != '\n' && c != EOF && c != '\0')
		i++;
	*line = malloc((i + 1) * sizeof(char));
	(*line)[i] = '\0';
	ft_strncpy(*line, help->buff, i);
	if (!help)
		return (0);
	ft_strcpy(copy, help->buff + i + (c != '\0'));
	ft_strcpy(help->buff, copy);
	if (!ft_strcmp(help->buff, ""))
		ft_lstdelet(g_buff, fd);
	return (c == '\n' || c == EOF);
}

char			*in_buff(const int fd, char **line, char *str, t_buff **g_buff)
{
	char	*copy;
	int		i;
	int		size;

	i = 0;
	while (str[i] != '\n' && str[i] != EOF && str[i] != '\0')
		i++;
	size = ft_strlen(*line);
	copy = malloc((size + i + 1) * sizeof(char));
	copy[size + i] = '\0';
	ft_strncpy(copy, *line, size);
	ft_strncpy(copy + size, str, i);
	if (*line)
		free(*line);
	if (i + 1 < (int)ft_strlen(str))
		ft_lstcreat(g_buff, fd, str + i + 1);
	return (copy);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			str[BUFF_SIZE + 1];
	static t_buff	*g_buff;

	if (!line)
		return (-1);
	if (out_buff(fd, line, &g_buff) == 1)
		return (1);
	while (1)
	{
		if ((i = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
		if (i == 0)
			return (ft_strlen(*line) != 0);
		str[i] = '\0';
		*line = in_buff(fd, line, str, &g_buff);
		i = 0;
		while (str[i] != '\n' && str[i] != EOF)
			i++;
		if (i < BUFF_SIZE)
			return (1);
	}
	return (1);
}
