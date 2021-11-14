#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include "../mlx/mlx.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_img
{
    void    *img_xpm;
    int    img_width;
    int    img_height;
}              t_img;

typedef struct s_map_data
{
    int     map_width;
    int     map_height;
    int     map_len;
    char    *map;
    t_img   imgs[7];
}              t_map_data;

typedef struct s_game
{
    void	*mlx_ptr;
    void	*win_ptr;
    int		pos_p;
    int		*pos_ms;
    int     mon_count;
    int     col_count;
    int		g_mon_ctr;
    int     loop_cnt;
    int     steps;
}               t_game;

t_game  g_game;

#define PLYR "assets/pacman/player.xpm"
#define COLL "assets/pacman/collectible.xpm"
#define WALL "assets/pacman/wall.xpm"
#define EMPTY "assets/pacman/empty.xpm"
#define EXIT "assets/pacman/exit.xpm"
#define MON1 "assets/pacman/mon1.xpm"
#define END "assets/pacman/game_end.xpm"



void	free_dp(char **i);
void	init_map(char *map_path, t_map_data *map_data);
int		plyr_move(int keycode, t_map_data *map_data);
int     mon_move(t_map_data *map_data);
void	init_imgs(t_map_data *map_data);
void	load_map(t_map_data *map_data);
void	check_map(t_map_data *map_data);
void	update_pos(t_map_data *map_data);
void    init_pos(t_map_data *map_data);


#endif