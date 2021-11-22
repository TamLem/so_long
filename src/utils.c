/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:22:01 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/21 18:26:07 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_chars(char *map)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	if (ft_strchr(map, 'C') == NULL || ft_strchr(map, '0') == NULL)
		err_handling("map should contain all elements.");
	while (*map != '\0')
	{
		if (*map == 'P')
			p++;
		if (*map == 'E')
			e++;
		if (*map != 'C' && *map != 'P' && *map == 'E' && *map == '\n'
			&& *map != '1' && *map != '0' && *map != 'M')
			err_handling("map contains forbidden elements.");
		map++;
	}
	if (p != 1 || e != 1)
		err_handling("Invalid map.");
}

void	check_map(t_map_data *map_data)
{
	char	**tmp;
	int		i;
	int		j;

	map_data->map_height = 0;
	tmp = ft_split(map_data->map, '\n');
	map_data->map_width = ft_strlen(tmp[0]);
	i = 0;
	while (tmp[i])
	{
		j = 0;
		if ((int)ft_strlen(tmp[i]) != map_data->map_width)
			err_handling("map should be rectangular.");
		while (tmp[i][j])
		{
			if ((tmp[i][j] != '1' && (i == 0 || tmp[i + 1] == NULL))
				|| (tmp[i][0] != '1' || tmp[i][map_data->map_width - 1] != '1'))
				err_handling("map should be surrounded by walls.");
			j++;
		}
		map_data->map_height++;
		i++;
	}	
	free_dp(tmp);
	check_map_chars(map_data->map);
}

void	free_dp(char **i)
{
	while (*i)
	{
		free(*i);
		i++;
	}
}

void	check_imgs(t_img *imgs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (imgs[i].img_xpm == NULL)
		{
			printf("%d\t %d\n", len, i);
			err_handling("missing game resources!");
		}
		i++;
	}
}

int	count_nchar(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
