#include "include/fdf.h"
#include "include/libft.h"

//void	line_drawing(t_coords st_end, t_win stuff, int color)
//{
//	int x1 = st_end.x1;
//	int x2 = st_end.x2;
//	int y1 = st_end.y1;
//	int y2 = st_end.y2;
//	int	dx;
//	int	dy;
//	int	e;

//	dx = x2 - x1;
//	dy = y2 - y1;

//	if (dx != 0)
//	{
//		if (dx > 0)
//		{
//			if (dy != 0)
//			{
//				if (dy > 0)
//				{
//					// vecteur oblique cadran 1
//					if (dx >= dy)
//					{
//						// vecteur oblique octant 1
//						e = dx;
//						dx = e * 2;
//						dy *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (x1++ == x2)
//								break ;
//							if ((e -= dy) < 0)
//							{
//								y1++;
//								e += dx;
//							}
//						}
//					}
//					else
//					{
//						// vecteur oblique octant 2
//						e = dy;
//						dy = e * 2;
//						dx *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (y1++ == y2)
//								break ;
//							if ((e -= dx) < 0)
//							{
//								x1++;
//								e += dy;
//							}
//						}
//					}
//				}
//				else // dy < 0 (dx > 0)
//				{
//					// vecteur oblique quadrant 4
//					if (dx >= -dy)
//					{
//						// octant 8
//						e = dx;
//						dx = e * 2;
//						dy *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (x1++ == x2)
//								break ;
//							if ((e += dy) < 0)
//							{
//								y1--;
//								e += dx;
//							}
//						}
//					}
//					else
//					{
//						// octant 7
//						e = dy;
//						dy = e * 2;
//						dx *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (y1-- == y2)
//								break ;
//							if ((e += dx) > 0)
//							{
//								x1++;
//								e += dy;
//							}
//						}
//					}
//				}
//			}
//			else // dy == 0 (dx > 0)
//			{
//				while (x1 != x2)
//				{
//					my_mlx_pixel_put(&stuff.img, x1, y1, color);
//					x1++;
//				}
//			}
//		}
//		else // dx < 0
//		{
//			if (dy != 0)
//			{
//				if (dy > 0)
//				{
//					// quadrant 2
//					if (-dx >= dy)
//					{
//						// octant 4
//						e = dx;
//						dx = e * 2;
//						dy *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (x1-- == x2)
//								break ;
//							if ((e += dy) >= 0)
//							{
//								y1++;
//								e += dx;
//							}
//						}
//					}
//					else
//					{
//						// octant 3
//						e = dy;
//						dy = e * 2;
//						dx *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (y1++ == y2)
//								break ;
//							if ((e += dx) <= 0)
//							{
//								x1--;
//								e += dy;
//							}
//						}
//					}
//				}
//				else // dy < 0 (dx < 0)
//				{
//					// quadran 3
//					if (dx <= dy)
//					{
//						// octant 5
//						e = dx;
//						dx = e * 2;
//						dy *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (x1-- == x2)
//								break ;
//							if ((e -= dy) >= 0)
//							{
//								y1--;
//								e += dx;
//							}
//						}
//					}
//					else // dx > dy
//					{
//						// octant 6
//						e = dy;
//						dy = e * 2;
//						dx *= 2;
//						while (1)
//						{
//							my_mlx_pixel_put(&stuff.img, x1, y1, color);
//							if (y1-- == y2)
//								break ;
//							if ((e -= dx) >= 0)
//							{
//								x1--;
//								e += dy;
//							}
//						}
//					}
//				}
//			}
//			else // dy = 0 (dx < 0)
//			{
//				while (x1 != x2)
//				{
//					my_mlx_pixel_put(&stuff.img, x1, y1, color);
//					x1--;
//				}
//			}
//		}
//	}
//	else // dx == 0
//	{
//		if (dy != 0)
//		{
//			if (dy > 0)
//			{
//				while (y1 != y2)
//				{
//					my_mlx_pixel_put(&stuff.img, x1, y1, color);
//					y1++;
//				}
//			}
//			else // dy < 0
//			{
//				while (y1 != y2)
//				{
//					my_mlx_pixel_put(&stuff.img, x1, y1, color);
//					y1--;
//				}
//			}
//		}
//	}
//	mlx_put_image_to_window(stuff.mlx, stuff.mlx_win, stuff.img.img, 500, 0);
//}

//typedef struct	s_vars {
//	void	*mlx;
//	void	*win;
//}				t_vars;

//int	ftclose(int keycode, t_vars *vars)
//{
//	mlx_destroy_window(vars->mlx, vars->win);
//	return (0);
//}

#include <stdio.h>
int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		fd2;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		printf("non\n");
	fd2 = open(av[1], O_RDONLY);
	if (fd2 < 0)
		printf("non\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	while (1)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		free(line);
	}
	printf("END\n");
}