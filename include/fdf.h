/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:02:54 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/17 18:14:49 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
	KEY_ESC = 53,
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
}	t_fdf;

int		get_color(t_point current, t_point start, t_point end);
void	dr_line(t_coord line, t_fdf *fdf);
void	draw_matrix(t_fdf *fdf);
void	free_fdf(t_fdf *fdf);
void	free_split(char **split);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_isendline(char *str);
char	*get_next_line(int fd);
t_map	*init_parse_map(t_map *map, char **mapc, char **line);
void	init_fdf(t_fdf *fdf, char **mapc);
int		check_hex(char *hex);
int		check_digit(char *str);
int		has_hex(char *num);
int		get_len(char **line);
char	**get_map(char *filename);
int		check_map(char **mapc);
char	**ft_split(char const *s, char c);
t_sec	set_sec(t_coord line);
int		ft_toupper(int c);
int		hex_to_dec(char *hex);
void	move_img(t_coord *icoord, t_fdf *fdf);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		ft_abs(int x);
char	*ft_strdup(char *src);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	my_exit(void);
#endif
