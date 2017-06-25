/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:31:16 by acolas            #+#    #+#             */
/*   Updated: 2017/06/25 17:57:59 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{

	// Les valeurs de retour !
	// 1: au cas ou on renvoie une chaine!
	// 0: si on renvoit rien !
	// -1: fail!!!
	// read renvoit -1 tu renvoie -1
	// si buff_size est negatif tu renvoit -1
	//
	// char **line -> c un char *line de main
	// et on recup l'adresse car on va alloue une chaine pour cette **line!
	//
	// l'objectif:
	// recup une ligne entre les \n \n ou sinon \0
	//
	// strjoin = si buffer lu mais pas de \n
	// strchr = si \n dans buffer
	//
	// un static char a utilise !!!!
	//
	// text.txt:
	// abcdef
	// 012345
	// 678901
	//
	static char		*tmp;
	char			buff[BUFF_SIZE + 1];		
	int				i;
	char			*tab;

	i = 0;
	while (*line)
	{
		if (!(tab = (char *)malloc(sizeof(char) * BUFF_SIZE)) || 
				fd == 0 || fd < 0)
			return (0);
		while (read(fd, buff, BUFF_SIZE) != 0)
		{	
			if (ft_strchr(buff, '\n') !=  0)
				return (1);
			else
				tmp = ft_strjoin(buff, tab);
			i++;
		}
	}
	return (0);
}

#include <stdio.h>

int		main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char	*line = NULL;

	while ((get_next_line(fd, &line)))
		printf("%s\n", line);
	close(fd);
	return (0);
}
