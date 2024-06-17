/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:09:03 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/17 16:32:39 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_hook(int keycode, t_wimap *r)
{
	mlx_destroy_image(r->win.mlx, r->win.im.img);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(r->win.mlx, r->win.mlx_win);
		free(r->win.mlx);
		ft_exit("");
	}
	win_init(&r->win, 0);
	if (keycode == 123)
		r->map.offset_x += 10;
	if (keycode == 124)
		r->map.offset_x -= 10;
	if (keycode == 126)
		r->map.offset_y += 10;
	if (keycode == 125)
		r->map.offset_y -= 10;
	if (keycode == 0)
		r->map.a -= 2;
	if (keycode == 2)
		r->map.a += 2;
	map_manager(r->path, &r->map);
	get_window(r->map, &r->win);
	return (0);
}

int	ft_red_cross(t_win *win)
{
	mlx_destroy_image(win->mlx, win->im.img);
	mlx_destroy_window(win->mlx, win->mlx_win);
	free(win->mlx);
	ft_exit("");
	return (0);
}

int	ft_scroll(int mouse_code, int x, int y, t_wimap *res)
{
	if (x && y)
	{
		if (mouse_code == 4)
			res->map.zoom *= 1.1;
		if (mouse_code == 5)
			res->map.zoom /= 1.1;
		mlx_destroy_image(res->win.mlx, res->win.im.img);
		win_init(&res->win, 0);
		map_manager(res->path, &res->map);
		get_window(res->map, &res->win);
	}
	return (0);
}
