/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:30:08 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/20 18:47:49 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_pos(t_map_data *map_data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	g_game.n_mon = 0;
	g_game.n_col = 0;
	while (map_data->map[i])
	{
		if (map_data->map[i] == 'M')
			g_game.n_mon++;
		if (map_data->map[i] == 'C')
			g_game.n_col++;
		i++;
	}
	g_game.pos_ms = (int *)malloc(g_game.n_mon * sizeof(int));
	g_game.pos_col = (int *)malloc(g_game.n_col * sizeof(int));
	if (g_game.pos_ms == NULL || g_game.pos_col == NULL)
		err_handling("internal memory error!");
	i = 0;
	k = 0;
	j = 0;
	while (map_data->map[i])
	{
		if (map_data->map[i] == 'P')
			g_game.pos_p = i;
		if (map_data->map[i] == 'M')
			g_game.pos_ms[j++] = i;
		if (map_data->map[i] == 'C')
			g_game.pos_col[k++] = i;
		if (map_data->map[i] == 'E')
			g_game.pos_exit = i;
		i++;
	}
}

void	update_pos(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = g_game.n_mon;
	while (map_data->map[i])
	{
		if (map_data->map[i] == 'M')
			g_game.pos_ms[--j] = i;
		i++;
	}
}

int	next_pos(char id, char dir, int pos, t_map_data *map_data)
{
	char	*map;
	int		width;

	map = map_data->map;
	width = map_data->map_width;
	if (id == 'P')
	{
		if (dir == 'A' && map[pos - 1] != '1'
			&& (map[pos - 1] != 'E' || g_game.n_col == 0))
			return (pos - 1);
		if (dir == 'S' && map[pos + width + 1] != '1'
			&& (map[pos + width + 1] != 'E' || g_game.n_col == 0))
			return (pos + width + 1);
		if (dir == 'D' && map[pos + 1] != '1'
			&& (map[pos + 1] != 'E' || g_game.n_col == 0))
			return (pos + 1);
		if (dir == 'W' && map[pos - width - 1] != '1'
			&& (map[pos - width - 1] != 'E' || g_game.n_col == 0))
			return (pos - width - 1);
	}
	if (id == 'M')
	{
		if (dir == 'A' && map[pos - 1] != '1' && map[pos - 1] != 'M')
			return (pos - 1);
		if (dir == 'S' && map[pos + width + 1] != '1'
			&& map[pos + width + 1] != 'M')
			return (pos + width + 1);
		if (dir == 'D' && map[pos + 1] != '1' && map[pos + 1] != 'M')
			return (pos + 1);
		if (dir == 'W' && map[pos - width - 1] != '1'
			&& map[pos - width - 1] != 'M')
			return (pos - width - 1);
	}
	return (pos);
}
