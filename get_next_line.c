/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:31:16 by acolas            #+#    #+#             */
/*   Updated: 2017/07/16 20:59:56 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_new_line(char *str, char *stat)
{
	int				i;
	char			*tmp;

	i = 0;
	printf("5\n");
	tmp = ft_strdup(ft_strchr(str + 1, '\n'));
	ft_memdel((void **)stat);
	ft_strcpy(stat, str);
	printf("OK");
	return(0);
}

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
	static char		*stat = NULL;
	char			buff[BUFF_SIZE + 1];		
	int				i;
	char			*str;
	char			*tmp;

	i = 0;
	tmp = ft_strnew(BUFF_SIZE + 1);
	if (!(line = (char **)malloc(sizeof(char *) * BUFF_SIZE + 1)))
			return (0);
	if (stat == 0)
		str = ft_strnew(BUFF_SIZE + 1);
	else
		str = stat;
	printf("2\n");
	while (ft_strchr(tmp, '\n') == NULL)
	{	
		if (read(fd, buff, BUFF_SIZE) < 0 || BUFF_SIZE < 0 || fd < 0)
		{
			printf("fail 1");
			return (-1);
		}
		tmp = ft_strjoin(str, buff);
	}
	printf("3\n");
	while (tmp[i] != '\n')
		i++;
	ft_strncpy(*line, tmp, i);
	if (ft_new_line(str, stat) != 0)
	{
		printf("fail 3");
		return (-1);
	}
	return (0);
}

int		main(void)
{
	int fd = open("test1", O_RDONLY);
	char	*line = NULL;

	printf("1\n");
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (0);
}
