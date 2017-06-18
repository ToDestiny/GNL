/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:31:16 by acolas            #+#    #+#             */
/*   Updated: 2017/06/18 20:18:49 by acolas           ###   ########.fr       */
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

	if (!(tab = (char **)malloc(sizeof(char *) * BUFF_SIZE)))
		return (-1);
	i = 0;
	while (read(fd, buff, BUFF_SIZE) != 0)
	{	
	while (*line[i] != '\n' || *line[i] != '\0')
		i++;
	ft_memcpy(line, tab, i);
}

int		main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char	*line = NULL;

	while ((get_next_line(fd, &line)))
		printf("%s\n", line);
	close(fd);
	return (0);
}
