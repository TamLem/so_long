/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:30:13 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/21 19:57:36 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_status(t_map_data *map_data)
{
	int	i;

	i = 0;
	while (i < g_game.n_mon)
	{
		if (g_game.pos_p == g_game.pos_ms[i])
		{
			mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
				map_data->base_imgs[8].img_xpm, map_data->map_width * 12,
				map_data->map_height * 6);
			g_game.g_status = 0;
		}
		i++;
	}
	if (g_game.pos_p == g_game.pos_exit && g_game.n_col == 0)
	{
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr,
			map_data->base_imgs[9].img_xpm, map_data->map_width * 12,
			map_data->map_height * 6);
		g_game.g_status = 0;
	}
}

int	plyr_move(int keycode, t_map_data *map_data)
{
	int	last_pos;

	last_pos = g_game.pos_p;
	map_data->map[g_game.pos_p] = '0';
	if (keycode == 0)
		g_game.pos_p = next_pos('A', g_game.pos_p, map_data);
	if (keycode == 1)
		g_game.pos_p = next_pos('S', g_game.pos_p, map_data);
	if (keycode == 2)
		g_game.pos_p = next_pos('D', g_game.pos_p, map_data);
	if (keycode == 13)
		g_game.pos_p = next_pos('W', g_game.pos_p, map_data);
	map_data->map[g_game.pos_p] = 'P';
	if (map_data->initial_map[g_game.pos_p] == 'C')
	{
		g_game.n_col--;
		map_data->initial_map[g_game.pos_p] = '0';
	}
	if (last_pos != g_game.pos_p)
		g_game.steps++;
	load_map(map_data);
	game_status(map_data);
	return (0);
}

int	track_plyr(int pos, int pos_p, t_map_data *map_data)
{
	char	*map;
	int		width;

	map = map_data->map;
	width = map_data->map_width;
	if ((pos - pos_p) > map_data->map_width || rand() % 2)
		if (map[pos - width - 1] != '1' && map[pos - width - 1] != 'M')
			return (pos - width - 1);
	if ((pos_p - pos) > map_data->map_width || rand() % 2)
		if (map[pos + width + 1] != '1' && map[pos + width + 1] != 'M')
			return (pos + width + 1);
	if (pos_p > pos)
		if (map[pos + 1] != '1' && map[pos + 1] != 'M')
			return (pos + 1);
	if (map[pos - 1] != '1' && map[pos - 1] != 'M')
		return (pos - 1);
	return (pos);
}

int	mon_move(t_map_data *map_data)
{
	int	i;

	g_game.loop_cnt++;
	if (g_game.loop_cnt % (6000 / g_game.level) != 0 || !g_game.g_status)
		return (1);
	i = 0;
	while (i < g_game.n_mon)
	{
		if (map_data->initial_map[g_game.pos_ms[i]] == 'C')
			map_data->map[g_game.pos_ms[i]] = 'C';
		else
			map_data->map[g_game.pos_ms[i]] = '0';
		g_game.pos_ms[i] = track_plyr(g_game.pos_ms[i], g_game.pos_p, map_data);
		map_data->map[g_game.pos_ms[i]] = 'M';
		i++;
	}
	load_map(map_data);
	game_status(map_data);
	return (0);
}
