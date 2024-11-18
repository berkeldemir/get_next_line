/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:33:46 by beldemir          #+#    #+#             */
/*   Updated: 2024/11/18 10:07:15 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char	*new;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	index = 0;
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	while (index < i)
	{
		new[index] = s1[index];
		index++;
	}
	while (index < i + j)
	{
		new[index] = s2[index - i];
		index++;
	}
	new[index] = '\0';
	return (new);
}
