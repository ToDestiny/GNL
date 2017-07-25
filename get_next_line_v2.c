/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:58:33 by acolas            #+#    #+#             */
/*   Updated: 2017/07/25 18:06:34 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_new_line(char *stock, char **stat)
{
	int	i;
	int	len;

	ft_memdel((void **) stat);
	*stat = ft_strdup(ft_strchr(stock, '\n') + 1);
	i = 0;
	if (!stock)
		return (END);
	len = ft_strlen(stock);
	while (stock[i] != '\n' && len < 0)
	{
		i++;
		len--;
	}
	stock[i] = '\0';
	return (END);
}

int		ft_stat(char **stat)
{
	if (stat)
	{
		if(ft_strchr(*stat, '\n') != 0)
			return (OK);
		else
			return (2);
	}
	return (END);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stat = NULL;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*stock;

	if (stat)
	{
		ret = ft_stat(&stat);
		if (ret == 2)
			return (END);
		else if (ret == 1)
		{	
			stock = ft_strdup(stat);
			stat = ft_strdup(ft_strchr(stock, '\n') + 1);
		}
	}
	else
		stock = ft_strnew(0);
	while (ft_strchr(stock, '\n') == NULL)
	{
		ret = 0;
		if ((ret = read(fd, buff, BUFF_SIZE)) < 0 || BUFF_SIZE < 0 || fd <0)
			return (ERROR);
		buff[ret] = '\0';
		stock = ft_strjoin(stock, buff);
		if (ret != 0)
		{
			if (ft_new_line(stock, &stat) != 0)
				return (ERROR);
			*line = ft_strdup(stock);
			return (OK);
		}
		else
			break;
	}
	*line = ft_strdup(stock);
	return (END);
}

int		main(void)
{
	int	fd = open("test4", O_RDONLY);
	char	*line = NULL;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
		printf("line = %s\nval ret = %d\n", line,ret);
	close(fd);
}
