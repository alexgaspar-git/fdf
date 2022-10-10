/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:43:20 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:31:31 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data != NULL)
	{
		data->mlx = mlx_init();
		if (data->mlx == NULL)
			return (NULL);
		data->win = mlx_new_window(data->mlx, W, H, "fdf");
		if (data->win == NULL)
			return (NULL);
		data->img = mlx_new_image(data->mlx, W, H);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
	}
	return (data);
}

static t_coord	*init_coord(void)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	if (coord != NULL)
	{
		coord->x1 = 0;
		coord->y1 = 0;
		coord->x2 = 0;
		coord->y2 = 0;
		coord->z1 = 0;
		coord->z2 = 0;
		coord->clr1 = 0;
		coord->clr2 = 0;
	}
	return (coord);
}

static t_mat	*init_mat(void)
{
	t_mat	*mat;

	mat = malloc(sizeof(t_mat));
	if (mat != NULL)
	{
		mat->lx = init_coord();
		if (mat->lx == NULL)
			return (NULL);
		mat->ly = init_coord();
		if (mat->ly == NULL)
			return (NULL);
		mat->x = 0;
		mat->y = 0;
	}
	return (mat);
}

static t_map	*init_map(char **mapc)
{
	t_map	*map;
	char	**line;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (map);
	map->row = get_len(mapc);
	line = ft_split(mapc[0], ' ');
	map->col = get_len(line);
	free_split(line);
	map->h = malloc(sizeof(long *) * map->row);
	if (map->h == NULL)
		return (NULL);
	map->clr = malloc(sizeof(unsigned int *) * map->row);
	if (map->clr == NULL)
		return (NULL);
	map = init_parse_map(map, mapc, line);
	free_split(mapc);
	return (map);
}

void	init_fdf(t_fdf *fdf, char **mapc)
{
	fdf->data = init_data();
	if (fdf->data == NULL)
		my_exit();
	fdf->mat = init_mat();
	if (fdf->mat == NULL)
		my_exit();
	fdf->map = init_map(mapc);
	if (fdf->map == NULL)
		my_exit();
	fdf->offsetx = 0;
	fdf->offsety = 0;
	fdf->zoom = 20;
}
