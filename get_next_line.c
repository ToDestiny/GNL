/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:31:16 by acolas            #+#    #+#             */
/*   Updated: 2017/07/04 20:04:50 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
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
	char			*str;

	i = 0;
	while (*line)
	{
		if (read(fd, buff, BUFF_SIZE) < 0 || BUFF_SIZE < 0 || fd < 0)
			return (-1);
		while (read(fd, buff, BUFF_SIZE) != 0)
		{	
			//memchr
			if (ft_memchr(line, '\n', BUFF_SIZE) !=  0)
			{
				// copie du debut de la string dans ?, sauvergarder la position de \n (str + i)
				return (1);
			}
			else
				// sauvegarde la string afin de la copier avec la suivante
				if (str != 0)
				{
					str = ft_strjoin(str, buff);
					printf("%s", str);
				}
				else
				{
					str = ft_strdup(buff);
					printf("%s", str);
				}
			i++;
		}
	}
	return (0);
}

#include <stdio.h>

int		main(void)
{
	int fd = open("test0", O_RDONLY);
	char	*line = NULL;

	get_next_line(fd, &line);
	//while ((get_next_line(fd, &line)))
		printf("%s\n", line);
	close(fd);
	return (0);
}
