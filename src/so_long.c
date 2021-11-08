#include "../include/so_long.h"

void	*mlx_ptr;
void	*win_ptr;
t_data	img;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int 	offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	init_map(char *map_path)
{
	int		fd;
	char	c;
	void	*img;
	int 	img_width;
	int 	img_height;
	int		pos_x = 0;
	int		pos_y = 0;

	fd = open(map_path, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			pos_x = 0;
			pos_y += img_height;
			continue ;
		}
		if (c == '1')
		{
			img = mlx_xpm_file_to_image(mlx_ptr, WALL, &img_width, &img_height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, pos_x, pos_y);
			pos_x += img_width;
		}
		if (c != '1')
		{
			img = mlx_xpm_file_to_image(mlx_ptr, DOT, &img_width, &img_height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, pos_x, pos_y);
			pos_x += img_height;
		}
	};

}


int main(void)
{
//	void	*path;
//	void	*img;
//	int 	img_width;
//	int 	img_height;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 960, 680, "so_long");

//	img.img = mlx_new_image(mlx_ptr, 720, 680);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	init_map("assets/maps/map2.ber");
//	img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
//
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_loop(mlx_ptr);

	return (0);
}