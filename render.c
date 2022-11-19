/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:43:39 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 13:38:31 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_map *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->player_);
	mlx_destroy_image(data->mlx, data->exit_);
	mlx_destroy_image(data->mlx, data->coins);
}

void	put_img(t_map *map, int width, int i, int j)
{
	if (map->map_m[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, width,
			i * IMG_SIZE);
	else if (map->map_m[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_, width,
			i * IMG_SIZE);
	else if (map->map_m[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->ground, width,
			i * IMG_SIZE);
	else if (map->map_m[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit_, width,
			i * IMG_SIZE);
	else if (map->map_m[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->coins, width,
			i * IMG_SIZE);
}

int	render(t_map *map)
{
	int	i;
	int	j;
	int	width;

	if (map->mlx_win == NULL)
		msg_error("Window can't be opened");
	i = 0;
	while (map->map_m[i])
	{
		j = 0;
		width = 0;
		while (map->map_m[i][j] && map->map_m[i][j] != '\n')
		{
			put_img(map, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
	return ;
}
