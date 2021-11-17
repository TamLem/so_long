/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:18:30 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/17 15:18:33 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void err_handling(char *err_msg)
{
	printf("Error\n%s\n", err_msg);
	exit(-1);
}

void	check_map(t_map_data *map_data)
{
	char **temp;
	int		i;
	int		j;

	map_data->map_height = 0;
	map_data->map_width = 0;
	temp = ft_split(map_data->map, '\n');
	map_data->map_width = ft_strlen(temp[0]);
	i = 0;
	while(temp[i])
	{
		j = 0;
		if((int)ft_strlen(temp[i]) != map_data->map_width)
			err_handling("map should be rectangular."); //error varying width
		while (temp[i][j])
		{
			if ( (temp[i][j] != '1' && (i == 0 || temp[i + 1] == NULL)) 
				|| (temp[i][0] != '1' || temp[i][map_data->map_width - 1] != '1'))
				err_handling("map should be surrounded by walls."); //error varying width
			j++;
		}
		map_data->map_height++;
		i++;
	}
	if (ft_strchr(map_data->map, 'C') == NULL || ft_strchr(map_data->map, 'P') == NULL
		|| ft_strchr(map_data->map, 'E') == NULL ||  ft_strchr(map_data->map, '0') == NULL)
		err_handling("map should contain all elements.");
	free_dp(temp);
}

void	init_map(char *map_path, t_map_data *map_data)
{
	int	fd;
	char c;
	int len;
	char **temp;

	len = 0;
	fd = open(map_path, O_RDONLY); //TODO error handling
	if(fd == -1)
		perror("map");
	while(read(fd, &c, 1))
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

void	init_bottom_imgs(t_map_data *map_data)
{
	map_data->nums[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, ZERO, 
							&(map_data->nums[0].img_width), &(map_data->nums[0].img_height));
	map_data->nums[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, ONE, 
							&(map_data->nums[0].img_width), &(map_data->nums[1].img_height));
	map_data->nums[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, TWO, 
							&(map_data->nums[0].img_width), &(map_data->nums[2].img_height));
	map_data->nums[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, THREE, 
							&(map_data->nums[0].img_width), &(map_data->nums[3].img_height));
	map_data->nums[4].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, FOUR, 
							&(map_data->nums[0].img_width), &(map_data->nums[4].img_height));
	map_data->nums[5].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, FIVE, 
							&(map_data->nums[0].img_width), &(map_data->nums[5].img_height));
	map_data->nums[6].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, SIX, 
							&(map_data->nums[0].img_width), &(map_data->nums[6].img_height));
	map_data->nums[7].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, SEVEN, 
							&(map_data->nums[0].img_width), &(map_data->nums[7].img_height));
	map_data->nums[8].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EIGHT, 
							&(map_data->nums[0].img_width), &(map_data->nums[8].img_height));
	map_data->nums[9].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, NINE, 
							&(map_data->nums[0].img_width), &(map_data->nums[9].img_height));
}


void	init_imgs(t_map_data *map_data)
{
 	map_data->imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EMPTY, 
							&(map_data->imgs[0].img_width), &(map_data->imgs[0].img_height));
	map_data->imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, WALL, 
							&(map_data->imgs[1].img_width), &(map_data->imgs[1].img_height));
	map_data->imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, PLYR, 
							&(map_data->imgs[2].img_width), &(map_data->imgs[2].img_height));
	map_data->imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, COLL, 
							&(map_data->imgs[3].img_width), &(map_data->imgs[3].img_height));
	map_data->imgs[4].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EXIT, 
							&(map_data->imgs[4].img_width), &(map_data->imgs[4].img_height));
	map_data->imgs[5].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, MON, 
							&(map_data->imgs[5].img_width), &(map_data->imgs[5].img_height));
	map_data->imgs[6].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, END, 
							&(map_data->imgs[6].img_width), &(map_data->imgs[6].img_height));
	map_data->imgs[7].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, MOVES, 
						&(map_data->imgs[7].img_width), &(map_data->imgs[7].img_height));
	map_data->imgs[8].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, LOSE, 
						&(map_data->imgs[8].img_width), &(map_data->imgs[8].img_height));
	map_data->imgs[9].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, WIN, 
						&(map_data->imgs[9].img_width), &(map_data->imgs[9].img_height));
}

void	load_img(t_img imgs[], char c, int *pos_x, int *pos_y)
{
	if (c == '0')
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, imgs[0].img_xpm, *pos_x, *pos_y);
	if (c == '1')
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, imgs[1].img_xpm, *pos_x, *pos_y);
	if (c == 'C')
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, imgs[3].img_xpm, *pos_x, *pos_y);
	if (c == 'E')
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, imgs[4].img_xpm, *pos_x, *pos_y);
	if (c == 'P')
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, imgs[2].img_xpm, *pos_x, *pos_y);
	if (c == 'M')
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, imgs[5].img_xpm, *pos_x, *pos_y);
	*pos_x += 32;
}

void	show_steps(int n, int *pos_x, int *pos_y, t_map_data *map_data)
{
	if (n < 10)
	{
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, 
		map_data->nums[n].img_xpm, *pos_x, *pos_y);
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
	int		pos_x = 0;
	int		pos_y = 0;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(map_data->map[i])
	{	
		if(map_data->map[i] == '\n')
		{
			pos_x = 0;
			pos_y += 32;
		}
		else 
			load_img(map_data->imgs, map_data->map[i], &pos_x, &pos_y);
		i++;
	}
	pos_y += 32;
	mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
		map_data->imgs[7].img_xpm, 0, pos_y);
	pos_x = 150;
	show_steps(g_game.steps, &pos_x, &pos_y, map_data);

	
}