/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:06:17 by acaillea          #+#    #+#             */
/*   Updated: 2021/10/25 12:06:19 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	s3 = ft_gnl_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && *s1)
		s3[++i] = *s1++;
	while (s2 && *s2)
		s3[++i] = *s2++;
	s3[++i] = '\0';
	return (s3);
}

void	ft_2free(char *s1, char *s2)
{
	if (s1)
	{
		free (s1);
		s1 = NULL;
	}
	if (s2)
	{
		free (s2);
		s2 = NULL;
	}
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size * count);
	if (!str)
		return (NULL);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
