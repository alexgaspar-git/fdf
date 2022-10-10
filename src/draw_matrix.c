/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:42:59 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:38:06 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_lx(t_fdf *fdf, int i, int j)
{
	fdf->mat->lx->x1 = fdf->mat->x;
	fdf->mat->lx->y1 = fdf->mat->y;
	fdf->mat->lx->x2 = fdf->mat->x + fdf->zoom;
	if (i == fdf->map->col - 1)
		fdf->mat->lx->x2 = fdf->mat->x;
	fdf->mat->lx->y2 = fdf->mat->y;
	fdf->mat->lx->z1 = fdf->map->h[j][i] * fdf->zoom;
	fdf->mat->lx->clr1 = fdf->map->clr[j][i];
	if (i < fdf->map->col - 1)
	{
		fdf->mat->lx->clr2 = fdf->map->clr[j][i + 1];
		fdf->mat->lx->z2 = fdf->map->h[j][i + 1] * fdf->zoom;
	}
}

static void	set_ly(t_fdf *fdf, int i, int j)
{
	fdf->mat->ly->x1 = fdf->mat->x;
	fdf->mat->ly->y1 = fdf->mat->y;
	fdf->mat->ly->x2 = fdf->mat->x;
	fdf->mat->ly->y2 = fdf->mat->y + fdf->zoom;
	if (j == fdf->map->row - 1)
		fdf->mat->ly->y2 = fdf->mat->y;
	fdf->mat->ly->z1 = fdf->map->h[j][i] * fdf->zoom;
	fdf->mat->ly->clr1 = fdf->map->clr[j][i];
	if (j < fdf->map->row - 1)
	{
		fdf->mat->ly->clr2 = fdf->map->clr[j + 1][i];
		fdf->mat->ly->z2 = fdf->map->h[j + 1][i] * fdf->zoom;
	}
}

static t_coord	conv_iso(t_coord *line)
{
	t_coord	icoord;

	icoord.x1 = (line->x1 - line->y1) * cos(0.523599);
	icoord.y1 = -line->z1 + (line->x1 + line->y1) * sin(0.523599);
	icoord.x2 = (line->x2 - line->y2) * cos(0.523599);
	icoord.y2 = -line->z2 + (line->x2 + line->y2) * sin(0.523599);
	icoord.clr1 = line->clr1;
	icoord.clr2 = line->clr2;
	return (icoord);
}

static void	prep_line(t_fdf *fdf, int type)
{
	t_coord	line;

	if (type == 0)
		line = conv_iso(fdf->mat->lx);
	if (type == 1)
		line = conv_iso(fdf->mat->ly);
	move_img(&line, fdf);
	dr_line(line, fdf);
}

void	draw_matrix(t_fdf *fdf)
{
	int	i;
	int	j;

	j = 0;
	fdf->mat->y = 0;
	while (j < fdf->map->row)
	{
		i = 0;
		fdf->mat->x = 0;
		while (i < fdf->map->col)
		{
			set_lx(fdf, i, j);
			set_ly(fdf, i, j);
			prep_line(fdf, 0);
			prep_line(fdf, 1);
			i++;
			fdf->mat->x = fdf->mat->lx->x2;
		}
		j++;
		fdf->mat->y = fdf->mat->ly->y2;
	}
	mlx_put_image_to_window(fdf->data->mlx,
		fdf->data->win, fdf->data->img, 0, 0);
}
