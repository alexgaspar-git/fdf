/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:38:12 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/17 18:01:43 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

static int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->data->mlx, fdf->data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	esc_window(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->data->mlx, fdf->data->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	check_filename(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	i -= 4;
	if (filename[i] != '.')
		return (0);
	if (filename[i + 1] != 'f')
		return (0);
	if (filename[i + 2] != 'd')
		return (0);
	if (filename[i + 3] != 'f')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**mapc;
	t_fdf	fdf;

	if (argc != 2)
	{
		write(2, "Invalid arguments\n", 18);
		return (1);
	}
	if (check_filename(argv[1]) == 0)
	{
		perror("Not a .fdf");
		return (2);
	}
	mapc = get_map(argv[1]);
	if (!mapc)
		return (3);
	if (check_map(mapc) == 0)
		return (4);
	init_fdf(&fdf, mapc);
	draw_matrix(&fdf);
	mlx_hook(fdf.data->win, ON_KEYDOWN, 1L << 0, esc_window, &fdf);
	mlx_hook(fdf.data->win, ON_DESTROY, 1L << 2, close_window, &fdf);
	mlx_loop(fdf.data->mlx);
	free_fdf(&fdf);
	return (0);
}
