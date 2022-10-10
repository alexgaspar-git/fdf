/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:02:47 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 23:06:36 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define W 1600
# define H 900

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_R = 15,
	KEY_I = 34,
	KEY_K = 40,
	KEY_PLUS = 69,
	KEY_MIN = 78,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_ESC = 53,
	ARROW_UP = 126,
	ARROW_LEFT = 123,
	ARROW_DOWN = 125,
	ARROW_RIGHT = 124
};

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_sec
{
	t_point	start;
	t_point	end;
	t_point	current;
}	t_sec;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
}	t_color;

typedef struct s_coord
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	z1;
	int	z2;
	int	clr1;
	int	clr2;
}	t_coord;

typedef struct s_mat
{
	t_coord	*lx;
	t_coord	*ly;
	int		x;
	int		y;
}	t_mat;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	long	**h;
	int		**clr;
	int		row;
	int		col;
}	t_map;

typedef struct s_bres
{
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	xincr;
	int	yincr;
	int	cex;
	int	cey;
}	t_bres;

typedef struct s_fdf
{
	t_data	*data;
	t_mat	*mat;
	t_map	*map;
	int		offsetx;
	int		offsety;
	int		zoom;
	float	height;
	int		key;
	int		w;
	int		a;
	int		s;
	int		d;
	int		epilepsy;
	int		iso;
	int		inv;
	int		white;
	int		black;
	double	alpha_x;
	double	alpha_y;
	double	alpha_z;
}	t_fdf;

int		get_color(t_point current, t_point start, t_point end, int remove);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	dr_line(t_coord line, t_fdf *fdf, int remove);
void	draw_matrix(t_fdf *fdf, int remove);
int		close_window(t_fdf *fdf);
void	my_exit(void);
void	draw_instructions(t_fdf *fdf, int white);
void	free_fdf(t_fdf *fdf);
void	free_split(char **split);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_isendline(char *str);
void	init_fdf(t_fdf *fdf, char **mapc);
void	init_hooks(t_fdf *fdf);
void	init_fdfparams(t_fdf *fdf);
t_map	*init_parse_map(t_map *map, char **mapc, char **line);
void	swap_bnw(t_fdf *fdf);
int		key_press(int keycode, t_fdf *fdf);
int		key_release(int keycode, t_fdf *fdf);
int		key_move(t_fdf *fdf);
char	**get_map(char *filename);
int		check_map(char **mapc);
int		get_len(char **line);
int		has_hex(char *num);
int		check_digit(char *str);
int		check_hex(char *hex);
void	move_img(t_coord *icoord, t_fdf *fdf);
t_coord	rotate_x(t_coord *line, double alpha);
t_coord	rotate_y(t_coord *line, double alpha);
t_coord	rotate_z(t_coord *line, double alpha);
char	**ft_split(char const *s, char c);
t_sec	set_sec(t_coord line);
int		ft_toupper(int c);
int		hex_to_dec(char *hex);
void	set_background(t_fdf *fdf, int color);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		ft_abs(int x);
char	*ft_strdup(char *src);
#endif