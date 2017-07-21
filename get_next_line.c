/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:31:16 by acolas            #+#    #+#             */
/*   Updated: 2017/07/21 16:58:26 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_new_line(char *stock, char *stat)
{
	char			*tmp;
	int i;

	stat = ft_strdup(ft_strchr(stock, '\n'));
	i = 0;
	while (stock[i] != '\n')
		++i;
	stock[i] = '\0';	
//	ft_memdel((void **)stock);
//	ft_memdel((void **)tmp);
	return(END);
}

int		get_next_line(const int fd, char **line)
{

	static char		*stat = NULL;
	char			buff[BUFF_SIZE + 1];		
	int				ret;
	char			*stock;

	if (stat)
		stock = ft_strdup(stat);
	else
		stock = ft_strnew(0);
	while (ft_strchr(stock, '\n') == NULL)
	{	
		if ((ret = read(fd, buff, BUFF_SIZE)) <= 0 || BUFF_SIZE < 0 || fd < 0)
			return (ERROR);
		buff[ret] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	if (ft_new_line(stock, stat) != 0)
		return (ERROR);
	*line = ft_strdup(stock);
	return (END);
}

int		main(void)
{
	int fd = open("test1", O_RDONLY);
	char	*line = NULL;

	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (0);
}
