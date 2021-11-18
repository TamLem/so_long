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
    char    *initial_map;
    t_img   imgs[11];
    t_img   nums[10];
}              t_map_data;

typedef struct s_game
{
    void	*mlx_ptr;
    void	*win_ptr;
    int		pos_p;
    int		*pos_ms;
    int     *pos_col;
    int     pos_exit;
    int     mon_count;
    int     col_count;
    int		g_status;
    int     loop_cnt;
    int     steps;
}               t_game;

t_game  g_game;

#define PLYR "assets/pacman/player.xpm"
#define COLL "assets/pacman/collectible.xpm"
#define WALL "assets/pacman/wall.xpm"
#define EMPTY "assets/pacman/empty.xpm"
#define DOOR_C "assets/pacman/door0.xpm"
#define DOOR_O "assets/pacman/door1.xpm"
#define MON "assets/pacman/mon.xpm"
#define END "assets/pacman/game_end.xpm"
#define ZERO "assets/pacman/nums/0.xpm"
#define ONE "assets/pacman/nums/1.xpm"
#define TWO "assets/pacman/nums/2.xpm"
#define THREE "assets/pacman/nums/3.xpm"
#define FOUR "assets/pacman/nums/4.xpm"
#define FIVE "assets/pacman/nums/5.xpm"
#define SIX "assets/pacman/nums/6.xpm"
#define SEVEN "assets/pacman/nums/7.xpm"
#define EIGHT "assets/pacman/nums/8.xpm"
#define NINE "assets/pacman/nums/9.xpm"
#define MOVES "assets/pacman/nums/moves.xpm"
#define LOSE "assets/pacman/gameover.xpm"
#define WIN "assets/pacman/win.xpm"


void	free_dp(char **i);
void	init_map(char *map_path, t_map_data *map_data);
int		plyr_move(int keycode, t_map_data *map_data);
int     mon_move(t_map_data *map_data);
void	init_imgs(t_map_data *map_data);
void	load_map(t_map_data *map_data);
void	check_map(t_map_data *map_data);
void	update_pos(t_map_data *map_data);
void    init_pos(t_map_data *map_data);
void    init_bottom_imgs(t_map_data *map_data);
void    err_handling(char *err_msg);
void	init_pos(t_map_data *map_data);
void	update_pos(t_map_data *map_data);
int		next_pos(char id, char dir, int pos, t_map_data *map_data);

#endif