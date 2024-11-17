/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:48 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/17 20:31:06 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}
static char *ft_read(int fd, char *reco)
{
    char *buff;
    char *temp;
    int retval;

    retval = 1;
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    while (!ft_strchr(reco, '\n') && retval != 0)
    {
        retval = read(fd, buff, BUFFER_SIZE);
        if (retval < 0)
        {
            free(buff);
            return (NULL);
        }
        buff[retval] = '\0';
        temp = reco;
        reco = ft_strjoin(reco, buff);
        if (!reco)
        {
            free(buff);
            free(temp);
            return (NULL);
        }
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
	while (reco[i + j] != '\0' && reco[i + j] != '\n')
	{
		ret[j] = reco[i + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char    *get_next_line(int fd)
{
	static char *reco = NULL;
	char        *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reco = ft_read(fd, reco);
	line = ft_line(reco);
	reco = ft_next(reco);
	return (line);
}
