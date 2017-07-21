/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:37:48 by acolas            #+#    #+#             */
/*   Updated: 2017/07/21 15:51:27 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char		*stat = NULL;
	char 			buff[BUFF_SIZE + 1];
	char			*stock;

	if (!stock)
		stock = ft_strnew(0);
	if (ft_strchr(stock, '\n') != 0)
		ft_getline(stock);

	
}
