/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:48 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/17 18:12:02 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static char *reco = NULL;
	char        *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reco = ft_read(fd, full);
	line = ft_line(fd, full);
	reco = ft_next(fd, full);
	return (full);
}

static void	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}
static char	*ft_read(int fd, char *full)
{
	char	*buff;
	int		retval;

	retval = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(full, '\n') && retval != 0)
	{
		retval = read(fd, buff, BUFFER_SIZE);
		if (retval < 0)
			return (buff = ft_free(buff));
		buff[retval] = '\0';
		full = ft_strjoin(full, buff);
		if (!full)
			return (buff = ft_free(buff)); 
	}
	free(buff);
	return (full);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("berk.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	
}


static char	*ft_line(char *full)
{
	
}