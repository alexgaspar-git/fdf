/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:43:44 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:50:52 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_img(t_coord *icoord, t_fdf *fdf)
{
	icoord->x1 = icoord->x1 + (W / 2) + fdf->offsetx;
	icoord->y1 = icoord->y1 + (H / 2) + fdf->offsety;
	icoord->x2 = icoord->x2 + (W / 2) + fdf->offsetx;
	icoord->y2 = icoord->y2 + (H / 2) + fdf->offsety;
}

t_coord	rotate_x(t_coord *line, double alpha)
{
	t_coord	rotx;

	rotx.x1 = line->x1;
	rotx.y1 = line->y1 * cos(alpha) + line->z1 * sin(alpha);
	rotx.z1 = -line->y1 * sin(alpha) + line->z1 * cos(alpha);
	rotx.x2 = line->x2;
	rotx.y2 = line->y2 * cos(alpha) + line->z2 * sin(alpha);
	rotx.z2 = -line->y2 * sin(alpha) + line->z2 * cos(alpha);
	rotx.clr1 = line->clr1;
	rotx.clr2 = line->clr2;
	return (rotx);
}

t_coord	rotate_y(t_coord *line, double alpha)
{
	t_coord	roty;

	roty.x1 = line->x1 * cos(alpha) + line->z1 * sin(alpha);
	roty.y1 = line->y1;
	roty.z1 = -line->x1 * sin(alpha) + line->z1 * cos(alpha);
	roty.x2 = line->x2 * cos(alpha) + line->z2 * sin(alpha);
	roty.y2 = line->y2;
	roty.z2 = -line->x2 * sin(alpha) + line->z2 * cos(alpha);
	roty.clr1 = line->clr1;
	roty.clr2 = line->clr2;
	return (roty);
}

t_coord	rotate_z(t_coord *line, double alpha)
{
	t_coord	rotz;

	rotz.x1 = line->x1 * cos(alpha) - line->y1 * sin(alpha);
	rotz.y1 = line->x1 * sin(alpha) + line->y1 * cos(alpha);
	rotz.z1 = line->z1;
	rotz.x2 = line->x2 * cos(alpha) - line->y2 * sin(alpha);
	rotz.y2 = line->x2 * sin(alpha) + line->y2 * cos(alpha);
	rotz.z2 = line->z2;
	rotz.clr1 = line->clr1;
	rotz.clr2 = line->clr2;
	return (rotz);
}
