/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dial.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:35:10 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/05 15:08:49 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

void	dial_one(t_coords co, t_data img, int color, int rev)
{
	int	e;

	e = co.dx;
	co.dx = e * 2;
	co.dy *= 2;
	while (1)
	{
		if (rev)
			my_mlx_pixel_put(&img, co.y1, co.x1, color);
		else
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
		if (co.x1++ == co.x2)
			break ;
		e -= co.dy;
		if (e < 0)
		{
			co.y1++;
			e += co.dx;
		}
	}
}

void	dial_two(t_coords co, t_data img, int color, int rev)
{
	int	e;

	e = co.dy;
	co.dy = e * 2;
	co.dx *= 2;
	while (1)
	{
		if (rev)
			my_mlx_pixel_put(&img, co.y1, co.x1, color);
		else
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
		if ((!rev && co.y1++ == co.y2) || (rev && co.y1-- == co.y2))
			break ;
		e += co.dx;
		if ((!rev && e <= 0) || (rev && e >= 0))
		{
			if (rev)
				co.x1++;
			else
				co.x1--;
			e += co.dy;
		}
	}
}

void	dial_three(t_coords co, t_data img, int color, int rev)
{
	int	e;

	e = co.dx;
	co.dx = e * 2;
	co.dy *= 2;
	while (1)
	{
		if (rev)
			my_mlx_pixel_put(&img, co.y1, co.x1, color);
		else
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
		if (co.x1-- == co.x2)
			break ;
		e -= co.dy;
		if (e >= 0)
		{
			co.y1--;
			e += co.dx;
		}
	}
}

void	dial_four(t_coords co, t_data img, int color, int rev)
{
	int	e;

	e = co.dy;
	co.dy = e * 2;
	co.dx *= 2;
	while (1)
	{
		if (rev)
			my_mlx_pixel_put(&img, co.y1, co.x1, color);
		else
			my_mlx_pixel_put(&img, co.x1, co.y1, color);
		if ((!rev && co.y1-- == co.y2) || (rev && co.y1++ == co.y2))
			break ;
		e += co.dx;
		if ((!rev && e > 0) || (rev && e < 0))
		{
			if (rev)
				co.x1--;
			else
				co.x1++;
			e += co.dy;
		}
	}
}
