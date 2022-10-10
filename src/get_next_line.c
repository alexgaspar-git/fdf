/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:20:13 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:30:10 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_getline(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = save[j];
	line[j] = '\0';
	return (line);
}

static char	*ft_saveline(char *save)
{
	int		i;
	int		j;
	char	*saved;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	saved = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!saved)
		return (NULL);
	j = 0;
	while (save[i])
		saved[j++] = save[i++];
	saved[j] = '\0';
	free(save);
	return (saved);
}

static char	*ft_totline(int fd, char *save)
{
	int		read_size;
	char	*buffer;

	buffer = malloc(sizeof(char) * (11));
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (read_size != 0 && ft_isendline(save) == NULL)
	{
		read_size = read(fd, buffer, 10);
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0)
		return (NULL);
	save = ft_totline(fd, save);
	if (!save)
		return (NULL);
	line = ft_getline(save);
	save = ft_saveline(save);
	return (line);
}
