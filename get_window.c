/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:28 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/06 14:38:32 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "include/libft.h"
#include <time.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static t_coords	init_co(t_vector *tab, t_coords *co, int n, int pos2)
{
	if (pos2)
	{
		co->x2 = tab[n].x;
		co->y2 = tab[n].y;
	}
	else
	{
		co->x1 = tab[n].x;
		co->y1 = tab[n].y;
	}
	return (*co);
}

void	get_window(t_map map, t_win *win)
{
	t_coords	co;
	int			i;
	int			count_iter;
	int			max_x;
	int			supp;
	clock_t start, end;
	double elapsed;

	i = 0;
	count_iter = 1;
	max_x = map.count.k;
	start = clock();
	while (map.count.i--)
	{
		init_co(map.tab, &co, i, 0);
		supp = (max_x * count_iter) - 1;
		if (i - (max_x - 1) >= 0 && i != max_x - 1)
			l_draw(init_co(map.tab, &co, i - max_x, 1), *win, map.tab[i].c);
		if (i != supp)
			l_draw(init_co(map.tab, &co, i + 1, 1), *win, map.tab[i].c);
		else
			count_iter++;
		i++;
	}
	end = clock();
	elapsed = ((double)end - start) / CLOCKS_PER_SEC;
	printf("%.2fs\n", elapsed);
}
