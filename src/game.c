#include "../include/so_long.h"

void init_pos(t_map_data *map_data)
{
	int	i;
	int	j;
	int k;

	i = 0;
	g_game.mon_count = 0;
	g_game.col_count = 0;
	while (map_data->map[i])
	{
		if (map_data->map[i] == 'M')
			g_game.mon_count++;
		if (map_data->map[i] == 'C')
			g_game.col_count++;
		i++;
	}
	g_game.pos_ms = (int *)malloc(g_game.mon_count);
	g_game.pos_col = (int *)malloc(g_game.col_count);
	if (g_game.pos_ms == NULL || g_game.pos_col == NULL)
		return ; //add error f()
	i = 0;
	k = g_game.col_count;
	j = g_game.mon_count;
	while(map_data->map[i]) 
	{
		if (map_data->map[i] == 'P')
				g_game.pos_p = i;
		if (map_data->map[i] == 'M')
			g_game.pos_ms[--j] = i;
		if (map_data->map[i] == 'C')
			g_game.pos_col[--k] = i;
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
	g_game.col_count = 0;
	while (map_data->map[i])
	{
		if (map_data->map[i] == 'C')
			g_game.col_count++;
		i++;
	}
	i = 0;
	j = g_game.mon_count;
	while(map_data->map[i]) 
	{
		if (map_data->map[i] == 'M')
			g_game.pos_ms[--j] = i;
		i++;
	}
}

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

int	next_pos(char id, char dir, int pos, t_map_data *map_data)
{
	char	*map;
	int 	width;

	map = map_data->map;
	width = map_data->map_width;
	if (id == 'P')
	{
		if (dir == 'A' && map[pos - 1] != '1' 
			&& (map[pos - 1] != 'E' || g_game.col_count == 0))
			return (pos - 1);
		if (dir == 'S' && map[pos + width + 1] != '1' 
			&& (map[pos + width + 1] != 'E' || g_game.col_count == 0))
			return (pos + width + 1);
		if (dir == 'D' && map[pos + 1] != '1' 
			&& (map[pos + 1] != 'E' || g_game.col_count == 0))
			return (pos + 1);
		if (dir == 'W' && map[pos - width - 1] != '1' 
			&& (map[pos - width - 1] != 'E' || g_game.col_count == 0))
			return (pos - width - 1);
	}
	if (id == 'M')
	{
		if (dir == 'A' && map[pos - 1] != '1' &&  map[pos - 1] != 'M')
			return (pos - 1);
		if (dir == 'S' && map[pos + width + 1] != '1' &&  map[pos + width + 1] != 'M')
			return (pos + width + 1);
		if (dir == 'D' && map[pos + 1] != '1' &&  map[pos + 1] != 'M')
			return (pos + 1);
		if (dir == 'W' && map[pos - width - 1] != '1' &&  map[pos - width - 1] != 'M')
			return (pos - width - 1);
	}
	return (pos);
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
	int col_pos;
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
			map_data->initial_map[g_game.pos_p] = '0';
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