/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 15:19:27 by acolas            #+#    #+#             */
/*   Updated: 2017/08/08 16:49:54 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int fd = open("test4", O_RDONLY);
	char	*line = NULL;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
		printf("line = %s\nval ret = %d\n", line, ret);
	close(fd);
}
