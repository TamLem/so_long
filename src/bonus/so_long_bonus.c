#include "../../include/so_long.h"
#include "unistd.h"
#include "stdlib.h"

int		main(void)
{
	t_map_data map_data;

	g_game.steps = 0;
	g_game.mlx_ptr = mlx_init();
	g_game.loop_cnt = 0;
	
	init_map("assets/maps/map3.ber", &map_data);
	check_map(&map_data);
	init_imgs(&map_data);
	g_game.win_ptr = mlx_new_window(g_game.mlx_ptr, map_data.map_width * 32 + 400, map_data.map_height * 32 + 600, "so_long");
	mlx_key_hook(g_game.win_ptr, plyr_move, &map_data);
	init_pos(&map_data);
	load_map(&map_data);
	mlx_loop_hook(g_game.mlx_ptr, mon_move, &map_data);
	mlx_loop(g_game.mlx_ptr);

	return (0);
}