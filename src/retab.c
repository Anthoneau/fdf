/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:19:16 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/26 16:26:23 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	retab(t_map *map)
{
	int	x;
	int	y;
	int	i;

	map->stence = get_stence(map);
	map->count.l = get_center(map, map->stence, 0);
	map->count.m = get_center(map, map->stence, 1);
	i = 0;
	y = 0;
	while (y < map->count.j)
	{
		x = 0;
		while (x < map->count.k)
		{
			map->tab[i] = map->tab2[i];
			get_perspective(*map, x++, y, i++);
		}
		y++;
	}
}

void	og_tab(t_map *map)
{
	int	x;
	int	y;
	int	i;

	map->zoom = 1.00;
	map->offset_x = 0;
	map->offset_y = 0;
	map->a = 26.57;
	map->stence = get_stence(map);
	map->count.l = get_center(map, map->stence, 0);
	map->count.m = get_center(map, map->stence, 1);
	i = 0;
	y = 0;
	while (y < map->count.j)
	{
		x = 0;
		while (x < map->count.k)
		{
			map->tab[i] = map->tab2[i];
			get_perspective(*map, x++, y, i++);
		}
		y++;
	}
}
