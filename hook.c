/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:09:03 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/10 18:11:55 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_hook(int keycode, t_wimap *res)
{
	mlx_destroy_image(res->win.mlx, res->win.img.img);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(res->win.mlx, res->win.mlx_win);
		free(res->win.mlx);
		ft_exit("");
	}
	else
	{
		res->win.img.img = mlx_new_image(res->win.mlx, WIN_LENGTH, WIN_HEIGHT);
		res->win.img.adr = mlx_get_data_addr(res->win.img.img, &res->win.img.bpp, &res->win.img.len, &res->win.img.e);
	}
	if (keycode == 123)
		res->map.offset_x += 10;
	if (keycode == 124)
		res->map.offset_x -= 10;
	if (keycode == 126)
		res->map.offset_y += 10;
	if (keycode == 125)
		res->map.offset_y -= 10;
	map_manager(res->path, &res->map);
	get_window(res->map, &res->win);
	return (0);
}

int	ft_red_cross(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img.img);
		mlx_destroy_window(win->mlx, win->mlx_win);
		free(win->mlx);
		ft_exit("");
	return (0);
}

int	ft_scroll(int mouse_code, int x, int y, t_wimap *res)
{
	if (mouse_code == 4)
		res->map.zoom *= 1.1;
	if (mouse_code == 5)
		res->map.zoom /= 1.1;
	mlx_destroy_image(res->win.mlx, res->win.img.img);
	res->win.img.img = mlx_new_image(res->win.mlx, WIN_LENGTH, WIN_HEIGHT);
	res->win.img.adr = mlx_get_data_addr(res->win.img.img, &res->win.img.bpp, &res->win.img.len, &res->win.img.e);
	map_manager(res->path, &res->map);
	get_window(res->map, &res->win);
	return (0);
}
