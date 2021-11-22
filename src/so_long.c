/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:31:02 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/21 20:00:55 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	err_handling(char *err_msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(err_msg, 1);
	exit(-1);
}

int	game_end(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
		mlx_destroy_image(g_game.mlx_ptr, map_data->base_imgs[i++].img_xpm);
	i = 0;
	while (i < 10)
		mlx_destroy_image(g_game.mlx_ptr, map_data->num_imgs[i++].img_xpm);
	i = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
			mlx_destroy_image(g_game.mlx_ptr, map_data->p_imgs[j][i++].img_xpm);
		j++;
	}
	mlx_destroy_window(g_game.mlx_ptr, g_game.win_ptr);
	free(g_game.pos_col);
	free(g_game.pos_ms);
	free(map_data->map);
	free(map_data->initial_map);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_map_data *map_data)
{
	if (keycode == 53)
		game_end(map_data);
	if ((keycode == 13 || (keycode > -1 && keycode < 4)) && g_game.g_status)
	{
		g_game.last_key = keycode;
		plyr_move(keycode, map_data);
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_map_data	map_data;

	if (argc != 2)
		err_handling("Wrong number of inputs.");
	init_map(argv[1], &map_data);
	g_game.steps = 0;
	g_game.mlx_ptr = mlx_init();
	g_game.loop_cnt = 1;
	g_game.g_status = 1;
	g_game.last_key = 2;
	check_map(&map_data);
	init_imgs(&map_data);
	g_game.level = 1;
	g_game.win_ptr = mlx_new_window(g_game.mlx_ptr, map_data.map_width * 32,
			map_data.map_height * 32 + 32, "so_long");
	mlx_key_hook(g_game.win_ptr, key_hook, &map_data);
	mlx_hook(g_game.win_ptr, 17, 1L << 3, game_end, &map_data);
	init_pos(&map_data);
	load_map(&map_data);
	mlx_loop(g_game.mlx_ptr);
	return (0);
}
