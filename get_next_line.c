/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 21:56:46 by acolas            #+#    #+#             */
/*   Updated: 2017/08/08 16:36:40 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_type	*ft_lstnew_gnl(int fd)
{
	t_type	*dell;

	dell = (t_type *)malloc(sizeof(*dell));
	dell->content = ft_strnew(1);
	dell->num = 1;
	dell->fd = fd;
	dell->next = NULL;
	return (dell);
}

static t_type	*ft_find_fd(t_type *stock, int fd)
{
	t_type	*dell;

	while (stock)
	{
		if (stock->fd == fd)
			break ;
		if (stock->next == NULL)
		{
			dell = ft_lstnew_gnl(fd);
			stock->next = dell;
			return (dell);
		}
		stock = stock->next;
	}
	return (stock);
}

static int		ft_print_gnl(t_type **dell, char **line)
{
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_strchr((*dell)->content, '\n')) != NULL)
	{
		*line = ft_strdup((*dell)->content);
		tmp2 = (*dell)->content;
		(*dell)->content = ft_strdup(tmp1 + 1);
		ft_strdel(&tmp2);
		return (OK);
	}
	return (END);
}

static int		ft_read_gnl(t_type **dell, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	tmp;

	while (((*dell)->num = read((*dell)->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[(*dell)->num] = '\0';
		tmp = *ft_strjoin((*dell)->content, buff);
		ft_strdel(&(*dell)->content);
		(*dell)->content = &tmp;
		if (ft_print_gnl(dell, line) == 1)
			return (OK);
	}
	return (END);
}

int				get_next_line(const int fd, char **line)
{
	static t_type	*stock;
	t_type			*dell;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (ERROR);
	if (!stock)
		stock = ft_lstnew_gnl(fd);
	dell = ft_find_fd(stock, fd);
	if ((ft_read_gnl(&dell, line) == 1))
		return (OK);
	if (dell->num == ERROR)
		return (ERROR);
	if (ft_strlen(dell->content) == 0)
		return (END);
	if (ft_print_gnl(&dell, line) == 1)
		return (OK);
	else
	{
		*line = ft_strdup(dell->content);
		ft_strclr(dell->content);
	}
	return (OK);
}
