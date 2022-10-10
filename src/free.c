/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:43:09 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:29:18 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	free_data(t_fdf *fdf)
{
	free(fdf->data->mlx);
	free(fdf->data->win);
	free(fdf->data->img);
	free(fdf->data);
}

static void	free_mat(t_fdf *fdf)
{
	free(fdf->mat->lx);
	free(fdf->mat->ly);
	free(fdf->mat);
}

static void	free_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map->row)
	{
		free(fdf->map->h[i]);
		free(fdf->map->clr[i]);
		i++;
	}
	free(fdf->map->h);
	free(fdf->map->clr);
	free(fdf->map);
}

void	free_fdf(t_fdf *fdf)
{
	free_data(fdf);
	free_mat(fdf);
	free_map(fdf);
}
