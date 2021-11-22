/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:18:30 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/21 19:57:44 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(char *map_path, t_map_data *map_data)
{
	int		fd;
	char	c;
	int		len;

	len = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		err_handling("map");
	while (read(fd, &c, 1))
		len++;
	close(fd);
	map_data->map = (char *)malloc(len + 1);
	map_data->initial_map = (char *)malloc(len + 1);
	if (map_data->map == NULL || map_data->initial_map == NULL)
		err_handling("could not allocte memory for the game.");
	map_data->map_len = len;
	fd = open(map_path, O_RDONLY);
	read(fd, map_data->map, len);
	map_data->map[len] = '\0';
	ft_strlcpy(map_data->initial_map, map_data->map, len);
}

void	load_pimg(t_map_data *map_data, int *pos_x, int *pos_y)
{
	static int	frame = 0;

	if (g_game.last_key == 0)
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
			map_data->p_imgs[1][frame].img_xpm, *pos_x, *pos_y);
	if (g_game.last_key == 13)
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
			map_data->p_imgs[2][frame].img_xpm, *pos_x, *pos_y);
	if (g_game.last_key == 1)
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
			map_data->p_imgs[3][frame].img_xpm, *pos_x, *pos_y);
	if (g_game.last_key == 2)
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
			map_data->p_imgs[0][frame].img_xpm, *pos_x, *pos_y);
	*pos_x += 32;
	if (++frame == 4)
		frame = 0;
}

void	load_img(t_img imgs[], char c, int *pos_x, int *pos_y)
{
	if (c == '0')
		mlx_put_image_to_window(g_game.mlx_ptr,
			g_game.win_ptr, imgs[0].img_xpm, *pos_x, *pos_y);
	if (c == '1')
		mlx_put_image_to_window(g_game.mlx_ptr,
			g_game.win_ptr, imgs[1].img_xpm, *pos_x, *pos_y);
	if (c == 'C')
		mlx_put_image_to_window(g_game.mlx_ptr,
			g_game.win_ptr, imgs[4].img_xpm, *pos_x, *pos_y);
	if (c == 'E' && g_game.n_col)
		mlx_put_image_to_window(g_game.mlx_ptr,
			g_game.win_ptr, imgs[3].img_xpm, *pos_x, *pos_y);
	if (c == 'E' && !g_game.n_col)
		mlx_put_image_to_window(g_game.mlx_ptr,
			g_game.win_ptr, imgs[2].img_xpm, *pos_x, *pos_y);
	if (c == 'M')
		mlx_put_image_to_window(g_game.mlx_ptr,
			g_game.win_ptr, imgs[5].img_xpm, *pos_x, *pos_y);
	*pos_x += 32;
}

void	show_steps(int n, int *pos_x, int *pos_y, t_map_data *map_data)
{
	if (n < 10)
	{
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
			map_data->num_imgs[n].img_xpm, *pos_x, *pos_y);
		*pos_x += 32;
	}
	if (n > 10)
	{
		show_steps(n / 10, pos_x, pos_y, map_data);
		show_steps(n % 10, pos_x, pos_y, map_data);
	}
}

void	load_map(t_map_data *map_data)
{
	int		pos_x;
	int		pos_y;
	int		i;

	i = 0;
	pos_x = 0;
	pos_y = 0;
	while (map_data->map[i])
	{	
		if (map_data->map[i] == '\n')
		{
			pos_x = 0;
			pos_y += 32;
		}
		else if (map_data->map[i] == 'P')
			load_pimg(map_data, &pos_x, &pos_y);
		else
			load_img(map_data->base_imgs, map_data->map[i], &pos_x, &pos_y);
		i++;
	}
	pos_y += 32;
	mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
		map_data->base_imgs[7].img_xpm, 0, pos_y);
	pos_x = 150;
	show_steps(g_game.steps, &pos_x, &pos_y, map_data);
}
