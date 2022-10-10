/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_reg_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:43:25 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:48:04 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_A || keycode == 97)
		fdf->a = 1;
	else if (keycode == KEY_W || keycode == 119)
		fdf->w = 1;
	else if (keycode == KEY_S || keycode == 115)
		fdf->s = 1;
	else if (keycode == KEY_D || keycode == 100)
		fdf->d = 1;
	else if (keycode == KEY_I || keycode == 105)
	{
		draw_matrix(fdf, fdf->black);
		if (fdf->iso == 1)
			fdf->iso = 0;
		else
			fdf->iso = 1;
	}
	else if (keycode == KEY_K)
		swap_bnw(fdf);
	else
		fdf->key = keycode;
	return (0);
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_A || keycode == 97)
		fdf->a = 0;
	else if (keycode == KEY_W || keycode == 119)
		fdf->w = 0;
	else if (keycode == KEY_S || keycode == 115)
		fdf->s = 0;
	else if (keycode == KEY_D || keycode == 100)
		fdf->d = 0;
	else
		fdf->key = -1;
	return (0);
}

static void	wasd(t_fdf *fdf)
{
	if (fdf->w == 1)
		fdf->offsety -= 1 * fdf->zoom;
	if (fdf->s == 1)
		fdf->offsety += 1 * fdf->zoom;
	if (fdf->a == 1)
		fdf->offsetx -= 1 * fdf->zoom;
	if (fdf->d == 1)
		fdf->offsetx += 1 * fdf->zoom;
}

static void	change_vals(t_fdf *fdf)
{
	if (fdf->key == KEY_R || fdf->key == 114)
		init_fdfparams(fdf);
	if (fdf->key == KEY_Q || fdf->key == 113)
		fdf->height += 0.05;
	if (fdf->key == KEY_E || fdf->key == 101)
		fdf->height -= 0.05;
	if (fdf->key == KEY_PLUS || fdf->key == 61)
		fdf->zoom += 1;
	if (fdf->key == KEY_MIN || fdf->key == 45)
		if (fdf->zoom - 1 > 0)
			fdf->zoom -= 1;
	if (fdf->key == KEY_Z || fdf->key == 122)
		fdf->alpha_z += 0.05;
	if (fdf->key == KEY_X || fdf->key == 120)
		fdf->alpha_z -= 0.05;
	if (fdf->key == ARROW_LEFT || fdf->key == 65361)
		fdf->alpha_y -= 0.05;
	if (fdf->key == ARROW_RIGHT || fdf->key == 65363)
		fdf->alpha_y += 0.05;
	if (fdf->key == ARROW_UP || fdf->key == 65362)
		fdf->alpha_x -= 0.05;
	if (fdf->key == ARROW_DOWN || fdf->key == 65364)
		fdf->alpha_x += 0.05;
}

int	key_move(t_fdf *fdf)
{
	draw_matrix(fdf, fdf->black);
	if (fdf->inv == 1)
		set_background(fdf, 0xFFFFFF);
	wasd(fdf);
	change_vals(fdf);
	if (fdf->key == KEY_ESC || fdf->key == 65307)
	{
		mlx_destroy_window(fdf->data->mlx, fdf->data->win);
		exit(EXIT_SUCCESS);
	}
	draw_matrix(fdf, fdf->white);
	mlx_put_image_to_window(fdf->data->mlx,
		fdf->data->win, fdf->data->img, 0, 0);
	draw_instructions(fdf, fdf->white);
	return (0);
}
