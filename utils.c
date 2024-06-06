/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:40:03 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/04 18:27:15 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "include/libft.h"

float	rad(void)
{
	return (26.57 * (M_PI / 180));
}

double	min(double i, double j)
{
	if (i > j)
		return (j);
	else
		return (i);
}

double	get_stence(t_map map)
{
	double	scale;
	double	iso_l;
	double	iso_h;

	iso_l = (map.count.j + map.count.k) * cos(M_PI / 6);
	iso_h = (map.count.j + map.count.k) * sin(M_PI / 6);
	scale = min((WIN_LENGTH / iso_l), (WIN_HEIGHT / iso_h)) * 0.536;
	return (scale);
}

double	get_center(t_map map, double stence, int ind)
{
	int		map_l;
	int		map_h;
	double	offset_x;
	double	offset_y;

	map_l = map.count.k;
	map_h = map.count.j;
	offset_x = (WIN_LENGTH - (map_l * stence)) / 2;
	offset_y = (WIN_HEIGHT - (map_h * stence)) / 2;
	if (ind)
		return (offset_y);
	else
		return (offset_x);
}

void	get_perspective(t_map map, int j, int n, int i)
{
	double	x;
	double	y;

	x = j * cos(rad()) + n * cos(rad() + 2) + map.tab[i].z * cos(rad() - 2);
	y = j * sin(rad()) + n * sin(rad() + 2) + map.tab[i].z * sin(rad() - 2);
	map.tab[i].x = map.count.l + x * map.stence;
	map.tab[i].y = map.count.m + y * map.stence;
}
