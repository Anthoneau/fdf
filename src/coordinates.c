/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:36:14 by agoldber          #+#    #+#             */
/*   Updated: 2024/06/18 18:58:25 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/libft.h"

static int	count_line(char *l)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (l[i])
	{
		if (ft_isdigit(l[i]) && (i == 0 || l[i - 1] == ' ' || l[i - 1] == '-'))
		{
			while (l[i] && ft_isdigit(l[i]))
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static t_ptw	count_tab(int fd)
{
	char	*line;
	t_ptw	count;

	count.i = 0;
	count.j = 0;
	count.k = 0;
	count.l = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count.l = count_line(line);
		count.i += count.l;
		if (count.k == 0)
			count.k = count.i;
		if (count.k == 0 || count.l != count.k)
			ft_exit("Problem with the map\n");
		count.j++;
		free(line);
	}
	return (count);
}

static int	grid_init(t_map map, char *line, int num, int i)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_split(line, ' ');
	if (!split)
		ft_exit("Problem with line");
	while (split[j] != NULL)
	{
		map.tab[i].z = ft_atoi(split[j]);
		map.tab[i].c = ft_atoi_base(split[j]);
		if (!(map.tab[i].c))
			map.tab[i].c = ft_atoi_base("0xffffff");
		map.tab2[i] = map.tab[i];
		get_perspective(map, j++, num, i++);
	}
	while (j--)
		free(split[j]);
	return (i);
}

static void	fill_tab(t_map map, int fd)
{
	char		*line;
	int			j;
	int			i;

	j = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = grid_init(map, line, j, i);
		j++;
		free(line);
	}
}

void	map_manager(char *path, t_map *map)
{
	int		fd;
	int		fd2;

	fd = open(path, O_RDONLY);
	fd2 = open(path, O_RDONLY);
	if (!fd || !fd2)
		ft_exit("Problem with file\n");
	map->count = count_tab(fd);
	map->tab = malloc(map->count.i * sizeof(t_vector));
	if (!map->tab)
		ft_exit("Problem with size allocation\n");
	map->tab2 = malloc(map->count.i * sizeof(t_vector));
	if (!map->tab2)
		ft_exit("Problem with size allocation\n");
	map->stence = get_stence(map);
	map->count.l = get_center(map, map->stence, 0);
	map->count.m = get_center(map, map->stence, 1);
	fill_tab(*map, fd2);
	close(fd);
	close(fd2);
}
