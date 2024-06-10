/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:33:16 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/10 18:19:26 by agoldber         ###   ########.fr       */
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

	title = ft_strdup("\\/\\/[Fil De Fer]\\/\\/");
	s.mlx = mlx_init();
	s.mlx_win = mlx_new_window(s.mlx, WIN_LENGTH, WIN_HEIGHT, title);
	s.img.img = mlx_new_image(s.mlx, WIN_LENGTH, WIN_HEIGHT);
	s.img.adr = mlx_get_data_addr(s.img.img, &s.img.bpp, &s.img.len, &s.img.e);
	return (s);
}

int	main(int ac, char **av)
{
	t_wimap	res;

	if (ac == 2)
	{
		res.map.zoom = 1.00;
		res.map.offset_x = 0;
		res.map.offset_y = 0;
		map_manager(av[1], &res.map);
		res.path = av[1];
		res.win = win_init();
		get_window(res.map, &res.win);
		free(res.map.tab);
		mlx_hook(res.win.mlx_win, 17, 0, (ft_red_cross), &res.win);
		mlx_hook(res.win.mlx_win, 2, 0, (ft_hook), &res);
		mlx_mouse_hook(res.win.mlx_win, (ft_scroll), &res);
		mlx_loop(res.win.mlx);
	}
	return (0);
}
