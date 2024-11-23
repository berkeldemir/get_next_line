/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:48 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/23 12:29:39 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *reco)
{
	char	*buff;
	int		retval;

	retval = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_strchr(reco, '\n') == NULL && retval != 0)
	{
		retval = read(fd, buff, BUFFER_SIZE);
		if (retval == -1)
			return (free(buff), NULL);
		buff[retval] = '\0';
		reco = ft_strjoin(reco, buff);
		if (!reco)
			return (free(buff), NULL);
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
	i = -1;
	while (reco[++i] != '\0' && reco[i] != '\n')
		line[i] = reco[i];
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
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(reco) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (reco[i])
		ret[j++] = reco[i++];
	ret[j] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*reco = NULL;
	char		*line;
	char		*newr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reco = ft_read(fd, reco);
	if (!reco)
		return (NULL);
	line = ft_line(reco);
	newr = ft_next(reco);
	if (!newr)
		return (free(reco), NULL);
	free(reco);
	reco = newr;
	return (line);
}
