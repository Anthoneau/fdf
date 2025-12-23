/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:40:03 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/24 14:22:56 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	rad(float a)
{
	return (a * (M_PI / 180));
}

double	min(double i, double j)
{
	if (i > j)
		return (j);
	else
		return (i);
}

double	get_stence(t_map *map)
{
	double	scale;
	double	iso_l;
	double	iso_h;

	iso_l = WIN_LENGTH / ((map->count.j + map->count.k) * cos(M_PI / 6));
	iso_h = WIN_HEIGHT / ((map->count.j + map->count.k) * sin(M_PI / 6));
	scale = (min(iso_l, iso_h) * 0.536) * map->zoom;
	return (scale);
}

double	get_center(t_map *map, double stence, int ind)
{
	int		map_l;
	int		map_h;
	double	offset_x;
	double	offset_y;

	map_l = map->count.k;
	map_h = map->count.j;
	offset_x = ((WIN_LENGTH - (map_l * (stence / 2))) / 2) - map->offset_x;
	offset_y = ((WIN_HEIGHT - (map_h * (stence / 2))) / 2) - map->offset_y;
	if (ind)
		return (offset_y);
	else
		return (offset_x);
}

void	get_perspective(t_map map, int j, int n, int i)
{
	double	x;
	double	y;
	float	r;

	r = rad(map.a);
	x = j * cos(r) + n * cos(r + 2) + map.tab[i].z * cos(r - 2);
	y = j * sin(r) + n * sin(r + 2) + map.tab[i].z * sin(r - 2);
	map.tab[i].x = map.count.l + x * map.stence;
	map.tab[i].y = map.count.m + y * map.stence;
}
