/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:01:15 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/17 14:11:48 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	draw_line(t_coords co, t_data img, int color)
{
	int	e2;

	while (1)
	{
		if ((co.x1 >= 0 && co.x1 < WIN_LENGTH)
			&& (co.y1 >= 0 && co.y1 < WIN_HEIGHT))
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
		if (co.x1 == co.x2 && co.y1 == co.y2)
			break ;
		e2 = co.e;
		if (e2 > -(co.dx))
		{
			co.e -= co.dy;
			co.x1 += co.sx;
		}
		if (e2 < co.dy)
		{
			co.e += co.dx;
			co.y1 += co.sy;
		}
	}
}

void	l_draw(t_coords co, t_win win, int color)
{
	co.dx = abs(co.x2 - co.x1);
	co.dy = abs(co.y2 - co.y1);
	if (co.x1 < co.x2)
		co.sx = 1;
	else
		co.sx = -1;
	if (co.y1 < co.y2)
		co.sy = 1;
	else
		co.sy = -1;
	if (co.dx > co.dy)
		co.e = co.dx / 2;
	else
		co.e = -(co.dy) / 2;
	draw_line(co, win.im, color);
}
