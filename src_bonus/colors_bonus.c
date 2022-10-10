/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:42:52 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:40:14 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, int remove)
{
	t_color	c;
	int		delta_x;
	int		delta_y;

	delta_x = ft_abs(end.x - start.x);
	delta_y = ft_abs(end.y - start.y);
	if (remove == 1)
		return (0);
	if (current.color == end.color)
		return (current.color);
	if (delta_x > delta_y)
		c.percentage = percent(start.x, end.x, current.x);
	else
		c.percentage = percent(start.y, end.y, current.y);
	c.red = get_light((start.color >> 16) & 0xFF, (end.color >> 16)
			& 0xFF, c.percentage);
	c.green = get_light((start.color >> 8) & 0xFF, (end.color >> 8)
			& 0xFF, c.percentage);
	c.blue = get_light(start.color & 0xFF, end.color & 0xFF, c.percentage);
	return ((c.red << 16) | (c.green << 8) | c.blue);
}
