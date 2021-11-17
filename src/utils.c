#include "../include/so_long.h"

void	free_dp(char **i)
{
	while (*i)
	{
		free(*i);
		i++;
	}
}

// void	move(char id, int pos, char dir, t_map_data *map_data)
// {
// 	map_data->map[next_pos(id, dir, pos, map_data)] = id;
// 	map_data->map[pos] = '0';
// 	game_status(map_data);
// 	update_pos(map_data);
// 	load_map(map_data);
// 	g_game.steps++;
// }

// int abs(int n)
// {
// 	if (n < 0)
// 		return(-1 * n);
// 	return (n);
// }

// void	print_circle(int c_x, int c_y, int rad)
// {
//     int	x;
//     int y;

//     x = rad;
//     y = rad;
//     while((x * x) + (y * y) >= (rad * rad))
//     {
//         while ((x * x) + (y * y) >= (rad * rad))
//         {
//             if ( (x * x) + (y * y) == (rad * rad))
//             {
//                 my_mlx_pixel_put(&img, c_x + x, c_y + y, 0xFF0000);
//                 my_mlx_pixel_put(&img, c_x - x, c_y - y, 0xFF0000);
//             }
//             x--;
//         }
//         x = rad;
//         y--;
//     }

// }


// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	int 	offset;

// 	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
// 	dst = data->addr + offset;
// 	*(unsigned int *)dst = color;
// }

// void print_img_info(t_data *img)
// {
//     printf("%p\n", img->img);
//     printf("%d\n", img->bits_per_pixel);
//     printf("%d\n", img->line_length);
//     printf("%d\n", img->endian);
// }