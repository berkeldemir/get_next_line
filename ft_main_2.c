/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:40:46 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/18 13:32:41 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read_2(int fd, char *reco)
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
			return (NULL);
		buff[retval] = '\0';
		temp = reco;
		reco = ft_strjoin(temp, buff);
		if (!reco)
			return (NULL);
		free(temp);
	}
	free(buff);
	return (reco);
}
#include <fcntl.h>
int main(void)
{
    //char    *s1 = "berk";
    //char    *s2 = "eldemir";
    int fd = open("a.txt", O_RDWR);
    printf("%s\n", ft_read_2(fd, (char *)0));
}