/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:33:29 by acolas            #+#    #+#             */
/*   Updated: 2017/07/16 17:48:45 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_type
{
	
}				t_type;

int		get_next_line(const int fd, char **line);

#endif
