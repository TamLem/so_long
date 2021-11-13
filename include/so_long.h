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
    t_img   imgs[5];
}              t_map_data;

int g_steps;

#define PLYR "assets/pacman/player.xpm"
#define COLL "assets/pacman/collectible.xpm"
#define WALL "assets/pacman/wall.xpm"
#define EMPTY "assets/pacman/empty.xpm"
#define EXIT "assets/pacman/exit.xpm"

void	free_dp(char **i);
// void	move(char dir);


#endif