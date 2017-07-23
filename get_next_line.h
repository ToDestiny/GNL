/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 14:31:21 by acolas            #+#    #+#             */
/*   Updated: 2017/07/23 18:48:21 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# define ERROR -1
# define OK 1
# define END 0
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
