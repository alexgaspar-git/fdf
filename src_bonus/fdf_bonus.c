/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:38:12 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/17 18:01:52 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->data->mlx, fdf->data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	draw_instructions(t_fdf *fdf, int white)
{
	int	color;

	if (white == 0)
		color = 0xFFFFFF;
	else
		color = 0;
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 25, color,
		"[WASD]: Move directions");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 50, color,
		"[R]: Reset");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 75, color,
		"[Q/E]: Increase/Decrease depth");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 100, color,
		"[I]: Change view (Isometric/Parallel)");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 125, color,
		"[+/-]: Zoom/Unzoom");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 150, color,
		"[Arrow keys]: Rotate X/Y axis");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 175, color,
		"[Z/X]: Rotate Z axis");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 200, color,
		"[K]: Toggle wireframe");
	mlx_string_put(fdf->data->mlx, fdf->data->win, 25, 225, color,
		"[ESC]: Quit");
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
	init_hooks(&fdf);
	free_fdf(&fdf);
	system("leaks fdf_bonus");
	return (0);
}
