/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:39:48 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/12 12:39:26 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
// # include <mlx.h>
# include <fcntl.h>
# define WIN_LENGTH 1920
# define WIN_HEIGHT 1080
# define ESCAPE 53

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
	int	c;
}	t_vector;

typedef struct s_data
{
	void	*img;
	char	*adr;
	int		bpp;
	int		len;
	int		e;
}	t_data;

typedef struct s_win
{
	void		*mlx;
	t_data		im;
	void		*mlx_win;
}	t_win;

typedef struct s_coords
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	e;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_coords;

typedef struct s_point_to_window
{
	int		i;
	int		j;
	int		k;
	double	l;
	double	m;
}	t_ptw;

typedef struct s_map
{
	t_vector	*tab;
	t_ptw		count;
	double		stence;
	int			offset_x;
	int			offset_y;
	double		zoom;
	float		a;
}	t_map;

typedef struct s_win_and_map
{
	t_map	map;
	t_win	win;
	char	*path;
}	t_wimap;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_exit(const char *str);
void	win_init(t_win *w, int i);
void	map_manager(char *path, t_map *map);
void	get_window(t_map map, t_win *stuff);
void	l_draw(t_coords st_end, t_win stuff, int color);
float	rad(float a);
double	min(double i, double j);
double	get_stence(t_map *map);
double	get_center(t_map *map, double stence, int ind);
void	get_perspective(t_map map, int j, int n, int i);
int		ft_hook(int keycode, t_wimap *res);
int		ft_red_cross(t_win *win);
int		ft_scroll(int mouse_code, int x, int y, t_wimap *res);

#endif