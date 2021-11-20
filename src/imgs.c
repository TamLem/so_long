/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:43 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/20 17:30:44 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_num_imgs(t_map_data *map_data)
{
	t_img	*imgs;

	imgs = map_data->num_imgs;
	imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, ZERO,
			&(imgs[0].img_width), &(imgs[0].img_height));
	imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, ONE,
			&(imgs[0].img_width), &(imgs[1].img_height));
	imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, TWO,
			&(imgs[0].img_width), &(imgs[2].img_height));
	imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, THREE,
			&(imgs[0].img_width), &(imgs[3].img_height));
	imgs[4].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, FOUR,
			&(imgs[0].img_width), &(imgs[4].img_height));
	imgs[5].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, FIVE,
			&(imgs[0].img_width), &(imgs[5].img_height));
	imgs[6].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, SIX,
			&(imgs[0].img_width), &(imgs[6].img_height));
	imgs[7].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, SEVEN,
			&(imgs[0].img_width), &(imgs[7].img_height));
	imgs[8].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EIGHT,
			&(imgs[0].img_width), &(imgs[8].img_height));
	imgs[9].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, NINE,
			&(imgs[0].img_width), &(imgs[9].img_height));
}

void	init_base_imgs(t_map_data *map_data)
{
	t_img	*imgs;

	imgs = map_data->base_imgs;
	imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EMPTY,
			&(imgs[0].img_width), &(imgs[0].img_height));
	imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, WALL,
			&(imgs[1].img_width), &(imgs[1].img_height));
	imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, DOOR_O,
			&(imgs[2].img_width), &(imgs[2].img_height));
	imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, DOOR_C,
			&(imgs[3].img_width), &(imgs[3].img_height));
	imgs[4].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, COLL,
			&(imgs[4].img_width), &(imgs[4].img_height));
	imgs[5].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, MON,
			&(imgs[5].img_width), &(imgs[5].img_height));
	imgs[6].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, END,
			&(imgs[6].img_width), &(imgs[6].img_height));
	imgs[7].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, MOVES,
			&(imgs[7].img_width), &(imgs[7].img_height));
	imgs[8].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, LOSE,
			&(imgs[8].img_width), &(imgs[8].img_height));
	imgs[9].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, WIN,
			&(imgs[9].img_width), &(imgs[9].img_height));
}

void	init_pimgs_LR(t_map_data *map_data)
{
	t_img	*imgs;

	imgs = map_data->p_imgs[0];
	imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R0,
			&(imgs[0].img_width), &(imgs[0].img_height));
	imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R1,
			&(imgs[1].img_width), &(imgs[1].img_height));
	imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R2,
			&(imgs[2].img_width), &(imgs[2].img_height));
	imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R3,
			&(imgs[3].img_width), &(imgs[3].img_height));
	imgs = map_data->p_imgs[1];
	imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L0,
			&(imgs[0].img_width), &(imgs[0].img_height));
	imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L1,
			&(imgs[1].img_width), &(imgs[1].img_height));
	imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L2,
			&(imgs[2].img_width), &(imgs[2].img_height));
	imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L3,
			&(imgs[3].img_width), &(imgs[3].img_height));
}

void	init_pimgs_UD(t_map_data *map_data)
{
	t_img	*imgs;

	imgs = map_data->p_imgs[2];
	imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U0,
			&(imgs[0].img_width), &(imgs[0].img_height));
	imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U1,
			&(imgs[1].img_width), &(imgs[1].img_height));
	imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U2,
			&(imgs[2].img_width), &(imgs[2].img_height));
	imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U3,
			&(imgs[3].img_width), &(imgs[3].img_height));
	imgs = map_data->p_imgs[3];
	imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D0,
			&(imgs[0].img_width), &(imgs[0].img_height));
	imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D1,
			&(imgs[1].img_width), &(imgs[1].img_height));
	imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D2,
			&(imgs[2].img_width), &(imgs[2].img_height));
	imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D3,
			&(imgs[3].img_width), &(imgs[3].img_height));
}

void	init_imgs(t_map_data *map_data)
{
	int	i;

	i = 0;
	init_base_imgs(map_data);
	init_num_imgs(map_data);
	init_pimgs_LR(map_data);
	init_pimgs_UD(map_data);
	check_imgs(map_data->base_imgs, 10);
	check_imgs(map_data->num_imgs, 10);
	check_imgs(map_data->p_imgs[0], 4);
	check_imgs(map_data->p_imgs[1], 4);
	check_imgs(map_data->p_imgs[2], 4);
	check_imgs(map_data->p_imgs[3], 4);
}
