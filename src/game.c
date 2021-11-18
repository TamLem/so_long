#include "../include/so_long.h"

void	game_status(t_map_data *map_data)
{
	int i;

	i = 0;
	while(i < g_game.mon_count)
	{
		if (g_game.pos_p == g_game.pos_ms[i])
		{
			mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, 
				map_data->imgs[8].img_xpm, map_data->map_width*12, map_data->map_height*6);
			g_game.g_status = 0;
		}
		i++;
	}
	if (g_game.pos_p == g_game.pos_exit && g_game.col_count == 0)
	{
		mlx_put_image_to_window(g_game.mlx_ptr, g_game.win_ptr, 
			map_data->imgs[9].img_xpm, map_data->map_width*12, map_data->map_height*6);
		g_game.g_status = 0;
	}
}

int	arr_includes(int x, int *a, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (a[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

int	plyr_move(int keycode, t_map_data *map_data)
{
	int last_pos;

	last_pos = g_game.pos_p;
	map_data->map[g_game.pos_p] = '0';
	if (keycode == 0)
		g_game.pos_p = next_pos('P', 'A', g_game.pos_p, map_data);
	if (keycode == 1)
		g_game.pos_p = next_pos('P', 'S', g_game.pos_p, map_data);
	if (keycode == 2)
		g_game.pos_p = next_pos('P', 'D', g_game.pos_p, map_data);
	if (keycode == 13)
		g_game.pos_p = next_pos('P', 'W', g_game.pos_p, map_data);
	map_data->map[g_game.pos_p] = 'P';
	if ( map_data->initial_map[g_game.pos_p] == 'C') 
	{
			g_game.col_count--;
			map_data->initial_map[g_game.pos_p] = '0';
	}
	load_map(map_data);
	if(last_pos != g_game.pos_p)
			g_game.steps++;
	game_status(map_data);
	return(0);
}

char plyr_dir(int pos_m, int pos_p, t_map_data *map_data)
{
	if ((pos_m - pos_p) > map_data->map_width)
		return ('W');
	if ((pos_p - pos_m) > map_data->map_width)
		return ('S');
	if (pos_p > pos_m)
		return ('D');
	else
		return ('A');
}

int	mon_move(t_map_data *map_data)
{
	int i;

	g_game.loop_cnt++;
	if (g_game.loop_cnt % 2000 != 0 || !g_game.g_status)
		return (1);
	i = 0;
	while(i < g_game.mon_count)
	{
		if (map_data->initial_map[g_game.pos_ms[i]] == 'C')
			map_data->map[g_game.pos_ms[i]] = 'C';
		else	
			map_data->map[g_game.pos_ms[i]] = '0';
		if (g_game.loop_cnt % 4000 == 0)
			map_data->map[next_pos('M', plyr_dir(g_game.pos_ms[i], g_game.pos_p, map_data),
			g_game.pos_ms[i], map_data)] = 'M';
		else
			map_data->map[next_pos('M', "WASD"[rand() % 4], g_game.pos_ms[i], map_data)] = 'M';
		i++;
	}
	update_pos(map_data);
	load_map(map_data);
	game_status(map_data);
	return (0);
}