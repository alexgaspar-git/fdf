/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:02:48 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/17 18:11:16 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->data->win, ON_KEYDOWN, 1L << 0, key_press, fdf);
	mlx_hook(fdf->data->win, ON_KEYUP, 1L << 1, key_release, fdf);
	mlx_hook(fdf->data->win, ON_DESTROY, 1L << 2, close_window, fdf);
	mlx_loop_hook(fdf->data->mlx, &key_move, fdf);
	mlx_loop(fdf->data->mlx);
}

void	init_fdfparams(t_fdf *fdf)
{
	fdf->offsetx = 0;
	fdf->offsety = 0;
	fdf->zoom = 20;
	fdf->height = 1;
	fdf->key = -1;
	fdf->w = 0;
	fdf->a = 0;
	fdf->s = 0;
	fdf->d = 0;
	fdf->epilepsy = 0;
	fdf->iso = 1;
	if (fdf->inv != 1)
	{
		fdf->inv = 0;
		fdf->black = 1;
		fdf->white = 0;
	}
	fdf->alpha_x = 0;
	fdf->alpha_y = 0;
	fdf->alpha_z = 0;
}

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
		if (map->h[y][x] == 0)
			map->clr[y][x] = 0xAFAFAF;
		else
			map->clr[y][x] = 0x53E0E8;
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

void	swap_bnw(t_fdf *fdf)
{
	if (fdf->inv == 0)
	{
		fdf->inv = 1;
		fdf->white = 1;
		fdf->black = 0;
	}
	else
	{
		set_background(fdf, 0);
		fdf->inv = 0;
		fdf->white = 0;
		fdf->black = 1;
	}
}
