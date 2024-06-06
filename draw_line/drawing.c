/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:14:41 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/05 15:08:54 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

static t_coords	coords_init(t_coords s, int dx, int dy, int rev)
{
	s.dx = dx;
	s.dy = dy;
	if (rev)
	{
		ft_swap(&s.x1, &s.y1);
		ft_swap(&s.x2, &s.y2);
		ft_swap(&s.dx, &s.dy);
	}
	return (s);
}

static void	straight_line(t_coords co, t_data img, int color)
{
	if (co.dx != 0)
	{
		ft_swap(&co.dx, &co.dy);
		ft_swap(&co.x1, &co.y1);
		ft_swap(&co.x2, &co.y2);
	}
	if (co.dx > 0)
	{
		while ((co.x1 - 1) != co.x2)
		{
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
			co.x1++;
		}
	}
	else
	{
		while ((co.x1 + 1) != co.x2)
		{
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
			co.x1--;
		}
	}
}

void	l_draw(t_coords st_end, t_win win, int color)
{
	int			dx;
	int			dy;

	dx = st_end.x2 - st_end.x1;
	dy = st_end.y2 - st_end.y1;
	if (dx == 0 || dy == 0)
		straight_line(coords_init(st_end, dx, dy, 0), win.img, color);
	if ((dx > 0 && dy > 0) && dx >= dy)
		dial_one(coords_init(st_end, dx, dy, 0), win.img, color, 0);
	else if ((dx > 0 && dy > 0) && dx < dy)
		dial_one(coords_init(st_end, dx, dy, 1), win.img, color, 1);
	else if ((dx < 0 && dy > 0) && (-dx) < dy)
		dial_two(coords_init(st_end, dx, dy, 0), win.img, color, 0);
	else if ((dx < 0 && dy > 0) && (-dx) >= dy)
		dial_two(coords_init(st_end, dx, dy, 1), win.img, color, 1);
	else if ((dx < 0 && dy < 0) && dx <= dy)
		dial_three(coords_init(st_end, dx, dy, 0), win.img, color, 0);
	else if ((dx < 0 && dy < 0) && dx > dy)
		dial_three(coords_init(st_end, dx, dy, 1), win.img, color, 1);
	else if ((dx > 0 && dy < 0) && dx < (-dy))
		dial_four(coords_init(st_end, dx, dy, 0), win.img, color, 0);
	else if ((dx > 0 && dy < 0) && dx >= (-dy))
		dial_four(coords_init(st_end, dx, dy, 1), win.img, color, 1);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img.img, 100, 100);
}
