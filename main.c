#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*adr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->adr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(void *mlx, void *mlx_win, t_data img)
{
	int	i = 0;
	int	j = 0;

	while (i < 550 || j < 550)
	{
		if (i < 550)
		{
			my_mlx_pixel_put(&img, i, j, 0xfffafa);
			i++;
		}
		else
		{
			my_mlx_pixel_put(&img, i, j, 0xfffafa);
			j++;
		}
	}
	while (i > 0 || j > 0)
	{
		if (i > 0)
		{
			my_mlx_pixel_put(&img, i, j, 0xfffafa);
			i--;
		}
		else
		{
			my_mlx_pixel_put(&img, i, j, 0xfffafa);
			j--;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 650, 270);
}

void	hexagon(void *mlx, void *mlx_win, t_data img)
{
	int	i = 200;
	int	j = 100;

	while (i < 350)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		i++;
	}
	while (j < 200)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		i++;
		j++;
	}
	while (j < 350)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		j++;
	}
	while (j < 450)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		i--;
		j++;
	}
	while (i > 200)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		i--;
	}
	while (j > 350)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		i--;
		j--;
	}
	while (j > 200)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		j--;
	}
	while (i > 200)
	{
		my_mlx_pixel_put(&img, i, j, 0xfffafa);
		i++;
		j--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 700, 270);
}

void	rainbow(void *mlx, void *mlx_win, t_data img)
{
	int	i = 0;
	int	j = 0;
	int	n = 700;

	while (i++ < 700)
	{
		j = 0;
		while (j <= n)
		{
			my_mlx_pixel_put(&img, i, j, 0xff0000);
			j++;
			my_mlx_pixel_put(&img, i, j, 0xffa500);
			j++;
			my_mlx_pixel_put(&img, i, j, 0xffff00);
			j++;
			my_mlx_pixel_put(&img, i, j, 0x54ff9f);
			j++;
			my_mlx_pixel_put(&img, i, j, 0x5f9ea0);
			j++;
			my_mlx_pixel_put(&img, i, j, 0x8b8b);
			j++;
			my_mlx_pixel_put(&img, i, j, 0xee82ee);
			j++;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 270);
}

int main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		i = 0;
	int		j = 0;
	int		Ii = 0;
	int		Ij = 0;

	mlx = mlx_init(); //renvoit un pointeur sur la loc de notre instance MLX
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //renvoit un pointeur sur la fenetre ouverte
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.adr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	//square(mlx, mlx_win, img);
	hexagon(mlx, mlx_win, img);
	//rainbow(mlx, mlx_win, img);
	mlx_loop(mlx); //fait le rendu de la fenetre
}
