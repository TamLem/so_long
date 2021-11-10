#include "../include/so_long.h"

void	*mlx_ptr;
void	*win_ptr;

void	init_imgs(t_map_data *map_data)
{
 	map_data->imgs[0].img_xpm = mlx_xpm_file_to_image(mlx_ptr, EMPTY, 
							&(map_data->imgs[0].img_width), &(map_data->imgs[0].img_height));
	map_data->imgs[1].img_xpm = mlx_xpm_file_to_image(mlx_ptr, WALL, 
							&(map_data->imgs[1].img_width), &(map_data->imgs[1].img_height));
	map_data->imgs[2].img_xpm = mlx_xpm_file_to_image(mlx_ptr, PLYR, 
							&(map_data->imgs[2].img_width), &(map_data->imgs[2].img_height));
	map_data->imgs[3].img_xpm = mlx_xpm_file_to_image(mlx_ptr, COLL, 
							&(map_data->imgs[3].img_width), &(map_data->imgs[3].img_height));
	map_data->imgs[4].img_xpm = mlx_xpm_file_to_image(mlx_ptr, EXIT, 
							&(map_data->imgs[4].img_width), &(map_data->imgs[4].img_height));
}

void	init_map(char *map_path, t_map_data *map_data)
{
	int	fd;
	char c;
	int len;
	char *temp;

	len = 0;
	fd = open(map_path, O_RDONLY); //TODO error handling
	while(read(fd, &c, 1))
		len++;
	temp = (char *)malloc(len + 1);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, temp, len);
	map_data->map = ft_split(temp, '\n');
	free(temp);
	map_data->map_width = ft_strlen(map_data->map[0]);
	int i = 0;
	while(map_data->map[i])
	{
		if((int)ft_strlen(map_data->map[i]) != map_data->map_width)
			break ;
		map_data->map_height++;
		i++;
	}
	init_imgs(map_data);
	//TODO validate map
		// all elements are avalaible
	// printf("width %d, height %d", map_data->map_width, map_data->map_height);
}

void	load_img(t_img imgs[], char c, int *pos_x, int *pos_y)
{
	if (c == '0')
		mlx_put_image_to_window(mlx_ptr, win_ptr, imgs[0].img_xpm, *pos_x, *pos_y);
	if (c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, imgs[1].img_xpm, *pos_x, *pos_y);
	if (c == 'C')
		mlx_put_image_to_window(mlx_ptr, win_ptr, imgs[3].img_xpm, *pos_x, *pos_y);
	if (c == 'E')
		mlx_put_image_to_window(mlx_ptr, win_ptr, imgs[4].img_xpm, *pos_x, *pos_y);
	if (c == 'P')
		mlx_put_image_to_window(mlx_ptr, win_ptr, imgs[2].img_xpm, *pos_x, *pos_y);
	if (c == '\n')
	{
		*pos_x = 200;
		*pos_y += 32;
	}
	else
		*pos_x += 32;
}

void	load_map(t_map_data *map_data)
{
	int		pos_x = 200;
	int		pos_y = 300;

	int	i = 0;
	int j;
	while(map_data->map[i])
	{
		j = 0;
		while(map_data->map[i][j])
		{
			load_img(map_data->imgs, map_data->map[i][j], &pos_x, &pos_y);
			j++;
		}
		load_img(map_data->imgs,'\n', &pos_x, &pos_y);
		i++;
	}
}

int main(void)
{
	t_map_data map_data;

	mlx_ptr = mlx_init();

	init_map("assets/maps/map2.ber", &map_data);
	win_ptr = mlx_new_window(mlx_ptr, map_data.map_width * 32 + 400, map_data.map_height * 32 + 600, "so_long");
	load_map(&map_data);
	mlx_loop(mlx_ptr);

	return (0);
}