#include "../include/so_long.h"

void	*mlx_ptr;
void	*win_ptr;
int		player_pos;

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
	char **temp;

	len = 0;
	fd = open(map_path, O_RDONLY); //TODO error handling
	while(read(fd, &c, 1))
		len++;
	close(fd);
	map_data->map = (char *)malloc(len + 1);
	map_data->map_len = len;
	fd = open(map_path, O_RDONLY);
	read(fd, map_data->map, len);
	map_data->map[len] = '\0';
	temp = ft_split(map_data->map, '\n');
	map_data->map_width = ft_strlen(temp[0]);
	int i = 0;
	while(temp[i])
	{
		if((int)ft_strlen(temp[i]) != map_data->map_width)
			break ;
		map_data->map_height++;
		i++;
	}
	free_dp(temp);
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
	*pos_x += 32;
}

void	load_map(t_map_data *map_data)
{
	int		pos_x = 200;
	int		pos_y = 300;

	int	i = 0;
	while(map_data->map[i])
	{
		if (map_data->map[i]== 'P')
			player_pos = i;
		if(map_data->map[i] == '\n')
		{
			pos_x = 200;
			pos_y += 32;
		}
		else
			load_img(map_data->imgs, map_data->map[i], &pos_x, &pos_y);
		i++;
	}
}

int print_keycode(int keycode, void *vars)
{
	vars = NULL;
	printf("%d\n", keycode);
	return (0);
}


int	move(int keycode, t_map_data *map_data)
{
	if (keycode == 0 && map_data->map[player_pos - 1] != '1')
	{
		map_data->map[player_pos] = '0';
		map_data->map[player_pos - 1] = 'P';
	}
	if (keycode == 1 && (map_data->map[player_pos + map_data->map_width + 1] != '1'))
	{
		map_data->map[player_pos] = '0';
		map_data->map[player_pos + map_data->map_width + 1] = 'P';
	}
	if (keycode == 2 && map_data->map[player_pos + 1] != '1')
	{
		map_data->map[player_pos] = '0';
		map_data->map[player_pos + 1] = 'P';
	}
	if (keycode == 13 && (map_data->map[player_pos - map_data->map_width - 1] != '1'))
	{
		map_data->map[player_pos] = '0';
		map_data->map[player_pos - map_data->map_width - 1] = 'P';
	}
	load_map(map_data);
	g_steps++;
	return(0);
}


int main(void)
{
	t_map_data map_data;

	g_steps = 0;
	player_pos = 0;
	mlx_ptr = mlx_init();

	init_map("assets/maps/map2.ber", &map_data);
	win_ptr = mlx_new_window(mlx_ptr, map_data.map_width * 32 + 400, map_data.map_height * 32 + 600, "so_long");
	mlx_key_hook(win_ptr, move, &map_data);
	load_map(&map_data);
	mlx_loop(mlx_ptr);

	return (0);
}