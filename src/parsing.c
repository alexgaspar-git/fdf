/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:43:35 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:34:28 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	file_count_col(char *filename)
{
	int		file;
	char	*line;
	int		col;

	file = open(filename, O_RDONLY);
	if (file < 0)
		my_exit();
	line = get_next_line(file);
	col = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(file);
		col++;
	}
	free(line);
	close(file);
	return (col);
}

char	**get_map(char *filename)
{
	int		file;
	int		n;
	char	**map;
	char	*tmp;

	file = open(filename, O_RDONLY);
	if (file < 0)
		my_exit();
	n = file_count_col(filename);
	map = malloc(sizeof(char *) * (n + 1));
	if (!map)
		return (NULL);
	tmp = get_next_line(file);
	n = 0;
	while (tmp != NULL)
	{
		map[n] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(file);
		n++;
	}
	map[n] = 0;
	close(file);
	return (map);
}

static int	free_split_return(char **tmp)
{
	free_split(tmp);
	return (0);
}

static int	check_line(char *num)
{
	char	**tmp;

	if (has_hex(num) == 0)
	{
		if (check_digit(num) == 0)
			return (0);
		if (ft_atoi(num) < -2147483648 || ft_atoi(num) > 2147483647)
			return (0);
	}
	else if (has_hex(num) == 1)
	{
		tmp = ft_split(num, ',');
		if (check_line(tmp[0]) == 0)
			return (free_split_return(tmp));
		if (check_hex(tmp[1]) == 0)
			return (free_split_return(tmp));
		free_split(tmp);
	}	
	else
		return (0);
	return (1);
}

int	check_map(char **mapc)
{
	char	**line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mapc[j])
	{
		i = 0;
		line = ft_split(mapc[j], ' ');
		while (line[i])
		{
			if (check_line(line[i]) == 0)
			{
				free_split(line);
				return (0);
			}
			i++;
		}
		free_split(line);
		j++;
	}
	return (1);
}
