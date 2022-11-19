/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:44:23 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 14:13:16 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_map *map, char *file)
{
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		msg_error("Can't establish connection between so_long & Display");
	map->mlx_win = mlx_new_window(map->mlx, \
		(count_line(map->map_m[0]) - 1) * IMG_SIZE, \
		map_linecount(map, file) * IMG_SIZE, "So_long");
	if (map->mlx_win == NULL)
	{
		free(map->mlx_win);
		msg_error("Window can't be opened");
	}
}

void	init_img(t_map *map)
{
	map->ground = mlx_xpm_file_to_image(map->mlx, "img/ground.xpm",
			&map->img_width, &map->img_height);
	map->wall = mlx_xpm_file_to_image(map->mlx, "img/wall.xpm",
			&map->img_width, &map->img_height);
	map->exit_ = mlx_xpm_file_to_image(map->mlx, "img/exit.xpm",
			&map->img_width, &map->img_height);
	map->player_ = mlx_xpm_file_to_image(map->mlx, "img/player.xpm",
			&map->img_width, &map->img_height);
	map->coins = mlx_xpm_file_to_image(map->mlx, "img/collectable.xpm",
			&map->img_width, &map->img_height);
}

int	handle_keypress(int keysym, t_map *data)
{
	if (keysym == 53)
		exit(0);
	else if (keysym == 0)
		move_player(data, keysym);
	else if (keysym == 1)
		move_player(data, keysym);
	else if (keysym == 2)
		move_player(data, keysym);
	else if (keysym == 13)
		move_player(data, keysym);
	return (0);
}

int	handle_btnrealease(t_map *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	return (0);
}

void	loop_images(t_map *data)
{
	mlx_loop_hook(data->mlx, &render, data);
	mlx_hook(data->mlx_win, 2, 1L, &handle_keypress, data);
	mlx_hook(data->mlx_win, 17, 1L, &handle_btnrealease, data);
	mlx_loop(data->mlx);
}
