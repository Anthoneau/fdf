/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:33:16 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/18 18:59:46 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

void	ft_exit(const char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	win_init(t_win *w, int i)
{
	char	*title;

	title = ft_strdup("\\/\\/[Fil De Fer]\\/\\/");
	if (i)
	{
		w->mlx = mlx_init();
		w->mlx_win = mlx_new_window(w->mlx, WIN_LENGTH, WIN_HEIGHT, title);
	}
	w->im.img = mlx_new_image(w->mlx, WIN_LENGTH, WIN_HEIGHT);
	w->im.adr = mlx_get_data_addr(w->im.img, &w->im.bpp, &w->im.len, &w->im.e);
}

int	main(int ac, char **av)
{
	t_wimap	res;

	if (ac == 2)
	{
		res.map.zoom = 1.00;
		res.map.offset_x = 0;
		res.map.offset_y = 0;
		res.map.a = 26.57;
		map_manager(av[1], &res.map);
		res.path = av[1];
		win_init(&res.win, 1);
		get_window(res.map, &res.win);
		mlx_hook(res.win.mlx_win, 17, 0, (ft_red_cross), &res);
		mlx_hook(res.win.mlx_win, 2, 0, (ft_hook), &res);
		mlx_mouse_hook(res.win.mlx_win, (ft_scroll), &res);
		mlx_loop(res.win.mlx);
	}
	return (0);
}
