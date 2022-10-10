/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:40:12 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:53:02 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_sec	set_sec(t_coord line)
{
	t_sec	n;

	n.start.x = line.x1;
	n.start.y = line.y1;
	n.start.color = line.clr1;
	n.end.x = line.x2;
	n.end.y = line.y2;
	n.end.color = line.clr2;
	n.current.x = 0;
	n.current.y = 0;
	n.current.color = 0;
	return (n);
}

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return (c);
}

static int	hex_pos(char *hexarr, char c)
{
	int	i;

	i = 0;
	while (hexarr[i])
	{
		if (hexarr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	hex_to_dec(char *hex)
{
	char	*hexarr;
	int		dec;
	int		i;

	hexarr = malloc(sizeof(char) * 17);
	if (!hexarr)
		my_exit();
	hexarr = "0123456789ABCDEF";
	dec = 0;
	i = 2;
	while (hex[i])
	{
		hex[i] = ft_toupper(hex[i]);
		dec = (dec * 16) + hex_pos(hexarr, hex[i]);
		i++;
	}
	return (dec);
}

void	set_background(t_fdf *fdf, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x <= W)
		{
			my_mlx_pixel_put(fdf->data, x, y, color);
			x++;
		}
		y++;
	}
}
