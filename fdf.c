/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:33:16 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/06 15:58:19 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "include/libft.h"

void	ft_exit(const char *str)
{
	ft_printf("%s", str);
	exit(0);
}

static t_win	win_init(void)
{
	t_win	s;
	char	*title;

	title = ft_strdup("/\\/[Fil De Fer]\\/\\");
	s.mlx = mlx_init();
	s.mlx_win = mlx_new_window(s.mlx, WIN_LENGTH, WIN_HEIGHT, title);
	s.img.img = mlx_new_image(s.mlx, WIN_LENGTH, WIN_HEIGHT);
	s.img.adr = mlx_get_data_addr(s.img.img, &s.img.bpp, &s.img.len, &s.img.e);
	return (s);
}

static int	ft_hook(int keycode, t_win *win)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_image(win->mlx, win->img.img);
		mlx_destroy_window(win->mlx, win->mlx_win);
		free(win->mlx);
		ft_exit("");
	}
	return (0);
}

static int	ft_red_cross(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img.img);
		mlx_destroy_window(win->mlx, win->mlx_win);
		free(win->mlx);
		ft_exit("");
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_win	win;

	if (ac == 2)
	{
		map = map_manager(av[1]);
		win = win_init();
		get_window(map, &win);
		free(map.tab);
		mlx_hook(win.mlx_win, 17, 0, (ft_hook), &win);
		mlx_hook(win.mlx_win, 2, 0, (ft_hook), &win);
		mlx_loop(win.mlx);
	}
	return (0);
}
