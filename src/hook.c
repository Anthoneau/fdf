/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:09:03 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/18 19:00:35 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_hook(int keycode, t_wimap *res)
{
	mlx_destroy_image(res->win.mlx, res->win.im.img);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(res->win.mlx, res->win.mlx_win);
		free(res->win.mlx);
		free(res->map.tab);
		free(res->map.tab2);
		ft_exit("");
	}
	win_init(&res->win, 0);
	if (keycode == 123)
		res->map.offset_x += 10;
	if (keycode == 124)
		res->map.offset_x -= 10;
	if (keycode == 126)
		res->map.offset_y += 10;
	if (keycode == 125)
		res->map.offset_y -= 10;
	if (keycode == 0)
		res->map.a -= 2;
	if (keycode == 2)
		res->map.a += 2;
	retab(&res->map);
	get_window(res->map, &res->win);
	return (0);
}

int	ft_red_cross(t_wimap *res)
{
	mlx_destroy_image(res->win.mlx, res->win.im.img);
	mlx_destroy_window(res->win.mlx, res->win.mlx_win);
	free(res->win.mlx);
	free(res->map.tab);
	free(res->map.tab2);
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
		retab(&res->map);
		get_window(res->map, &res->win);
	}
	return (0);
}
