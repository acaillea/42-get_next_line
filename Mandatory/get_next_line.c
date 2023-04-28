/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:05:50 by acaillea          #+#    #+#             */
/*   Updated: 2021/10/25 12:05:55 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (NULL);
}

char	*get_return_line(char *mem_buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (mem_buff && !mem_buff[i])
		return (NULL);
	while (mem_buff[i] && mem_buff[i] != '\n')
		i++;
	line = ft_gnl_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	while (mem_buff[j] && j < i)
	{
		line[j] = mem_buff[j];
		j++;
	}
	if (mem_buff[j] == '\n')
		line[j] = mem_buff[j];
	line[++j] = '\0';
	return (line);
}

char	*get_next_buff(char *mem_buff)
{
	char			*new_buff;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (mem_buff && mem_buff[i] && mem_buff[i] != '\n')
		i++;
	if (!mem_buff[i])
		return (ft_free(mem_buff));
	new_buff = ft_gnl_calloc((ft_strlen(mem_buff) - (i - 1)), sizeof(char));
	if (!new_buff)
		return (ft_free(mem_buff));
	i++;
	while (mem_buff[i])
		new_buff[j++] = mem_buff[i++];
	new_buff[j] = '\0';
	free(mem_buff);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*mem_buff;
	char		*buff;
	char		*line;
	char		*tmp;
	int			rd;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	while (rd > 0 && (!(ft_strchr(mem_buff, '\n'))))
	{
		buff = ft_gnl_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (ft_free(buff));
		buff[rd] = '\0';
		tmp = mem_buff;
		mem_buff = ft_strjoin(mem_buff, buff);
		ft_2free (buff, tmp);
	}
	line = get_return_line(mem_buff);
	mem_buff = get_next_buff(mem_buff);
	return (line);
}
