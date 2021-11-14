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
		if (map_data->map[i] == 'P')
				g_game.pos_p = i;
		if (map_data->map[i] == 'M')
			g_game.pos_ms[--j] = i;
		i++;
	}
}

void	game_end(int pass)
{
	if (pass)
	{

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
			printf("Game over!");
			exit(0);
		}
		if (g_game.pos_p == g_game.pos_exit && g_game.col_count == 0)
		{
			printf("Sucess!");
			exit(0);
		}
		i++;
	}
}

void	move(char id, int pos_x, char dir, t_map_data *map_data)
{
	if (dir == 'A' && map_data->map[pos_x - 1] != '1')
	{
		map_data->map[pos_x] = '0';
		map_data->map[pos_x - 1] = id;
	}
	if (dir == 'S' && (map_data->map[pos_x + map_data->map_width + 1] != '1'))
	{
		map_data->map[pos_x] = '0';
		map_data->map[pos_x + map_data->map_width + 1] = id;
	}
	if (dir == 'D' && map_data->map[pos_x + 1] != '1')
	{
		map_data->map[pos_x] = '0';
		map_data->map[pos_x + 1] = id;
	}
	if (dir == 'W' && (map_data->map[pos_x - map_data->map_width - 1] != '1'))
	{
		map_data->map[pos_x] = '0';
		map_data->map[pos_x - map_data->map_width - 1] = id;
	}
	if (id == 'M')
	{
		int j = 0;
		while(j < g_game.col_count)
		{
			if (g_game.pos_col[j++] == pos_x)
				map_data->map[pos_x] = 'C';
		}
	}
	game_status(map_data);
	update_pos(map_data);
	load_map(map_data);
	g_game.steps++;
}

int abs(int n)
{
	if (n < 0)
		return(-1 * n);
	return (n);
}

int	plyr_move(int keycode, t_map_data *map_data)
{
	if (keycode == 0)
		move('P', g_game.pos_p, 'A', map_data);
	if (keycode == 1)
		move('P', g_game.pos_p, 'S', map_data);
	if (keycode == 2)
		move('P', g_game.pos_p, 'D', map_data);
	if (keycode == 13)
		move('P', g_game.pos_p, 'W', map_data);	
	return(0);
}

int	mon_move(t_map_data *map_data)
{
	int i;

	i = 0;
	if (g_game.loop_cnt++ % 2000 != 0)
		return (1);
	while(i < g_game.mon_count)
	{
		if (g_game.pos_ms[i] > g_game.pos_p && g_game.loop_cnt % 4000 == 0)
			move('M', g_game.pos_ms[i], 'W', map_data);
		else if( g_game.loop_cnt % 4000 == 0)
			move('M', g_game.pos_ms[i], 'S', map_data);
		if (g_game.pos_ms[i] > g_game.pos_p && g_game.loop_cnt % 4000 == 0)		
			move('M', g_game.pos_ms[i], 'A', map_data);
		else if( g_game.loop_cnt % 4000 == 0)
			move('M', g_game.pos_ms[i], 'D', map_data);
		move('M', g_game.pos_ms[i], "WASD"[rand() % 4], map_data);
		i++;
	}
	return (0);
}