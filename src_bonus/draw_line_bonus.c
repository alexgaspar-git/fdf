/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:21:04 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:54:43 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	dr_line_one(t_coord line, t_bres bres, t_fdf *fdf, int remove)
{
	int		i;
	t_sec	k;

	k = set_sec(line);
	i = 0;
	while (i <= bres.cex)
	{
		k.current.x = line.x1;
		k.current.y = line.y1;
		if (line.x1 < W && line.y1 < H && line.x1 > -1 && line.y1 > -1)
			my_mlx_pixel_put(fdf->data, line.x1, line.y1,
				get_color(k.current, k.start, k.end, remove));
		line.x1 += bres.xincr;
		bres.ex -= bres.dy;
		if (bres.ex < 0)
		{
			line.y1 += bres.yincr;
			bres.ex += bres.dx;
		}
		i++;
	}
}

static void	dr_line_two(t_coord line, t_bres bres, t_fdf *fdf, int remove)
{
	int		i;
	t_sec	k;

	k = set_sec(line);
	i = 0;
	while (i <= bres.cey)
	{
		k.current.x = line.x1;
		k.current.y = line.y1;
		if (line.x1 < W && line.y1 < H && line.x1 > -1 && line.y1 > -1)
			my_mlx_pixel_put(fdf->data, line.x1, line.y1,
				get_color(k.current, k.start, k.end, remove));
		line.y1 += bres.yincr;
		bres.ey -= bres.dx;
		if (bres.ey < 0)
		{
			line.x1 += bres.xincr;
			bres.ey += bres.dy;
		}
		i++;
	}
}

static t_bres	init_bres(t_coord line)
{
	t_bres	bres;

	bres.ex = ft_abs(line.x2 - line.x1);
	bres.ey = ft_abs(line.y2 - line.y1);
	bres.dx = 2 * bres.ex;
	bres.dy = 2 * bres.ey;
	bres.xincr = 1;
	if (line.x1 > line.x2)
		bres.xincr = -1;
	bres.yincr = 1;
	if (line.y1 > line.y2)
		bres.yincr = -1;
	bres.cex = bres.ex;
	bres.cey = bres.ey;
	return (bres);
}

void	dr_line(t_coord line, t_fdf *fdf, int remove)
{
	t_bres	bres;

	bres = init_bres(line);
	if (bres.ex >= bres.ey)
		dr_line_one(line, bres, fdf, remove);
	if (bres.ex < bres.ey)
		dr_line_two(line, bres, fdf, remove);
}
