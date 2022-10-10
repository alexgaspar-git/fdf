/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:02:48 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/17 18:08:47 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_height(t_map *map, int x, int y, char *line)
{
	char	**hex;

	if (has_hex(line) == 1)
	{
		hex = ft_split(line, ',');
		map->h[y][x] = ft_atoi(hex[0]);
		map->clr[y][x] = hex_to_dec(hex[1]);
		free_split(hex);
	}
	else if (has_hex(line) == 0)
	{
		map->h[y][x] = ft_atoi(line);
		map->clr[y][x] = 0xFFFFFF;
	}
}

t_map	*init_parse_map(t_map *map, char **mapc, char **line)
{
	int		x;
	int		y;

	y = 0;
	while (mapc[y])
	{
		x = 0;
		line = ft_split(mapc[y], ' ');
		if (get_len(line) != map->col)
			return (NULL);
		map->h[y] = malloc(sizeof(long) * map->col);
		if (map->h[y] == NULL)
			return (NULL);
		map->clr[y] = malloc(sizeof(unsigned int) * map->col);
		if (map->clr[y] == NULL)
			return (NULL);
		while (line[x])
		{
			parse_height(map, x, y, line[x]);
			x++;
		}
		y++;
		free_split(line);
	}
	return (map);
}
