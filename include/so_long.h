#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_img
{
	void	*img_xpm;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_map_data
{
	int		map_width;
	int		map_height;
	int		map_len;
	char	*map;
	char	*initial_map;
	t_img	base_imgs[10];
	t_img	p_imgs[4][4];
	t_img	num_imgs[10];
}			t_map_data;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		pos_p;
	int		*pos_ms;
	int		*pos_col;
	int		pos_exit;
	int		n_mon;
	int		n_col;
	int		g_status;
	int		loop_cnt;
	int		steps;
	int		last_key;
}			t_game;

t_game		g_game;

# define P_R0 "assets/pacman/pacman_right/r0.xpm"
# define P_R1 "assets/pacman/pacman_right/r1.xpm"
# define P_R2 "assets/pacman/pacman_right/r2.xpm"
# define P_R3 "assets/pacman/pacman_right/r3.xpm"

# define P_L0 "assets/pacman/pacman_left/l0.xpm"
# define P_L1 "assets/pacman/pacman_left/l1.xpm"
# define P_L2 "assets/pacman/pacman_left/l2.xpm"
# define P_L3 "assets/pacman/pacman_left/l3.xpm"

# define P_U0 "assets/pacman/pacman_up/u0.xpm"
# define P_U1 "assets/pacman/pacman_up/u1.xpm"
# define P_U2 "assets/pacman/pacman_up/u2.xpm"
# define P_U3 "assets/pacman/pacman_up/u3.xpm"

# define P_D0 "assets/pacman/pacman_down/d0.xpm"
# define P_D1 "assets/pacman/pacman_down/d1.xpm"
# define P_D2 "assets/pacman/pacman_down/d2.xpm"
# define P_D3 "assets/pacman/pacman_down/d3.xpm"

# define PLYR "assets/pacman/player.xpm"
# define COLL "assets/pacman/collectible.xpm"
# define WALL "assets/pacman/wall.xpm"
# define EMPTY "assets/pacman/empty.xpm"
# define DOOR_C "assets/pacman/door0.xpm"
# define DOOR_O "assets/pacman/door1.xpm"
# define MON "assets/pacman/mon.xpm"
# define END "assets/pacman/game_end.xpm"
# define ZERO "assets/pacman/nums/0.xpm"
# define ONE "assets/pacman/nums/1.xpm"
# define TWO "assets/pacman/nums/2.xpm"
# define THREE "assets/pacman/nums/3.xpm"
# define FOUR "assets/pacman/nums/4.xpm"
# define FIVE "assets/pacman/nums/5.xpm"
# define SIX "assets/pacman/nums/6.xpm"
# define SEVEN "assets/pacman/nums/7.xpm"
# define EIGHT "assets/pacman/nums/8.xpm"
# define NINE "assets/pacman/nums/9.xpm"
# define MOVES "assets/pacman/nums/moves.xpm"
# define LOSE "assets/pacman/gameover.xpm"
# define WIN "assets/pacman/win.xpm"

void	free_dp(char **i);
void	init_map(char *map_path, t_map_data *map_data);
int		plyr_move(int keycode, t_map_data *map_data);
int		mon_move(t_map_data *map_data);
void	init_imgs(t_map_data *map_data);
void	init_pimgs(t_map_data *map_data);
void	load_map(t_map_data *map_data);
void	check_map(t_map_data *map_data);
void	update_pos(t_map_data *map_data);
void	init_pos(t_map_data *map_data);
void	init_bottom_imgs(t_map_data *map_data);
void	err_handling(char *err_msg);
void	init_pos(t_map_data *map_data);
void	update_pos(t_map_data *map_data);
int		next_pos(char id, char dir, int pos, t_map_data *map_data);
void	init_bottom_imgs(t_map_data *map_data);
void	check_imgs(t_img *imgs, int len);
void	err_handling(char *err_msg);

#endif