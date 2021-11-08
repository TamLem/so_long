#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include "../mlx/mlx.h"
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}               t_data;

#define PM "assets/pacman_right/5d72db29886347f1d4b46b5fe7e88f086AHte1DvRApesLBF-0.xpm"
#define MON "assets/pacman/monster1.xpm"
#define WALL "assets/pacman/wall.xpm"
#define DOT "assets/pacman/dot.xpm"

#endif