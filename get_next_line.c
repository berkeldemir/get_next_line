/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:48 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/18 12:16:26 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_free(char *ptr, char *ptr2)
{
	free(ptr);
	if (ptr2)
		free(ptr2);
	return (NULL);
}


static char *ft_read(int fd, char *reco)
{
	char	*buff;
	char	*temp;
	int		retval;

	retval = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_strchr(reco, '\n') == NULL && retval != 0)
	{
		retval = read(fd, buff, BUFFER_SIZE);
		if (retval == -1)
			return (ft_free(buff, reco));
		buff[retval] = '\0';
		temp = reco;
		reco = ft_strjoin(temp, buff);
		if (!reco)
			return (free(buff), ft_free(temp, NULL));
		free(temp);
	}
	free(buff);
	return (reco);
}


static char	*ft_line(char *reco)
{
	char	*line;
	int		i;
	int		len;

	if (!reco || reco[0] == '\0')
		return (NULL);
	len = 0;
	while (reco[len] != '\0' && reco[len] != '\n')
		len++;
	if (reco[len] == '\0')
		line = (char *)malloc(sizeof(char) * (len + 1));
	else
		line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (reco[i] != '\0' && reco[i] != '\n')
	{
		line[i] = reco[i];
		i++;
	}
	if (reco[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_next(char *reco)
{
	int		i;
	int		j;
	char	*ret;

	if (!reco || reco[0] == '\0')
		return (NULL);
	i = 0;
	while (reco[i] != '\0' && reco[i] != '\n')
		i++;
	if (reco[i] == '\0')
	{
		free(reco);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (ft_strlen(reco) - i + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (reco[i + j + 1] != '\0')
	{
		ret[j] = reco[i + j];
		j++;
	}
	ret[j] = '\0';
	free(reco);
	return (ret);
}

char    *get_next_line(int fd)
{
	static char *reco;
	char        *line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reco = ft_read(fd, reco);
	if (!reco)
		return (NULL);
	//line = ft_line(reco);
	//reco = ft_next(reco);
	return (line);
}
