/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:43 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/18 21:58:19 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	init_bottom_imgs(t_map_data *map_data)
{
	map_data->nums[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, ZERO, 
							&(map_data->nums[0].img_width), &(map_data->nums[0].img_height));
	map_data->nums[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, ONE, 
							&(map_data->nums[0].img_width), &(map_data->nums[1].img_height));
	map_data->nums[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, TWO, 
							&(map_data->nums[0].img_width), &(map_data->nums[2].img_height));
	map_data->nums[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, THREE, 
							&(map_data->nums[0].img_width), &(map_data->nums[3].img_height));
	map_data->nums[4].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, FOUR, 
							&(map_data->nums[0].img_width), &(map_data->nums[4].img_height));
	map_data->nums[5].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, FIVE, 
							&(map_data->nums[0].img_width), &(map_data->nums[5].img_height));
	map_data->nums[6].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, SIX, 
							&(map_data->nums[0].img_width), &(map_data->nums[6].img_height));
	map_data->nums[7].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, SEVEN, 
							&(map_data->nums[0].img_width), &(map_data->nums[7].img_height));
	map_data->nums[8].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EIGHT, 
							&(map_data->nums[0].img_width), &(map_data->nums[8].img_height));
	map_data->nums[9].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, NINE, 
							&(map_data->nums[0].img_width), &(map_data->nums[9].img_height));
}


void	init_imgs(t_map_data *map_data)
{
 	map_data->imgs[0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, EMPTY, 
							&(map_data->imgs[0].img_width), &(map_data->imgs[0].img_height));
	map_data->imgs[1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, WALL, 
							&(map_data->imgs[1].img_width), &(map_data->imgs[1].img_height));
	// map_data->imgs[2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, PLYR, 
	// 						&(map_data->imgs[2].img_width), &(map_data->imgs[2].img_height));
	map_data->imgs[3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, COLL, 
							&(map_data->imgs[3].img_width), &(map_data->imgs[3].img_height));
	map_data->imgs[4].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, DOOR_C, 
							&(map_data->imgs[4].img_width), &(map_data->imgs[4].img_height));
	map_data->imgs[5].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, MON, 
							&(map_data->imgs[5].img_width), &(map_data->imgs[5].img_height));
	map_data->imgs[6].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, END, 
							&(map_data->imgs[6].img_width), &(map_data->imgs[6].img_height));
	map_data->imgs[7].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, MOVES, 
						&(map_data->imgs[7].img_width), &(map_data->imgs[7].img_height));
	map_data->imgs[8].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, LOSE, 
						&(map_data->imgs[8].img_width), &(map_data->imgs[8].img_height));
	map_data->imgs[9].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, WIN, 
						&(map_data->imgs[9].img_width), &(map_data->imgs[9].img_height));
	map_data->imgs[10].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, DOOR_O, 
						&(map_data->imgs[10].img_width), &(map_data->imgs[10].img_height));
	int i = 0;
	while (i < 10)
	{
		if (map_data->imgs[i].img_xpm == NULL)
		{
			printf("NUll XPM at index %d", i);
			err_handling("Couldn't find images");
		}
		i++;
	}
}

void	init_pimgs(t_map_data *map_data)
{

	map_data->p_imgs[0][0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R0, 
							&(map_data->p_imgs[0][0].img_width), &(map_data->p_imgs[0][0].img_height));
	map_data->p_imgs[0][1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R1, 
							&(map_data->p_imgs[0][1].img_width), &(map_data->p_imgs[0][1].img_height));
	map_data->p_imgs[0][2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R2, 
							&(map_data->p_imgs[0][2].img_width), &(map_data->p_imgs[0][2].img_height));
	map_data->p_imgs[0][3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_R3, 
							&(map_data->p_imgs[0][3].img_width), &(map_data->p_imgs[0][3].img_height));
							
	map_data->p_imgs[1][0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L0, 
							&(map_data->p_imgs[1][0].img_width), &(map_data->p_imgs[1][0].img_height));
	map_data->p_imgs[1][1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L1, 
							&(map_data->p_imgs[1][1].img_width), &(map_data->p_imgs[1][1].img_height));
	map_data->p_imgs[1][2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L2, 
							&(map_data->p_imgs[1][2].img_width), &(map_data->p_imgs[1][2].img_height));
	map_data->p_imgs[1][3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_L3, 
							&(map_data->p_imgs[1][3].img_width), &(map_data->p_imgs[1][3].img_height));

	map_data->p_imgs[2][0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U0, 
							&(map_data->p_imgs[2][0].img_width), &(map_data->p_imgs[2][0].img_height));
	map_data->p_imgs[2][1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U1, 
							&(map_data->p_imgs[2][1].img_width), &(map_data->p_imgs[2][1].img_height));
	map_data->p_imgs[2][2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U2, 
							&(map_data->p_imgs[2][2].img_width), &(map_data->p_imgs[2][2].img_height));
	map_data->p_imgs[2][3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_U3, 
							&(map_data->p_imgs[2][3].img_width), &(map_data->p_imgs[2][3].img_height));

	map_data->p_imgs[3][0].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D0, 
							&(map_data->p_imgs[3][0].img_width), &(map_data->p_imgs[3][0].img_height));
	map_data->p_imgs[3][1].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D1, 
							&(map_data->p_imgs[3][1].img_width), &(map_data->p_imgs[3][1].img_height));
	map_data->p_imgs[3][2].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D2, 
							&(map_data->p_imgs[3][2].img_width), &(map_data->p_imgs[3][2].img_height));
	map_data->p_imgs[3][3].img_xpm = mlx_xpm_file_to_image(g_game.mlx_ptr, P_D3, 
							&(map_data->p_imgs[3][3].img_width), &(map_data->p_imgs[3][3].img_height));
}