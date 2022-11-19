/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:42:44 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/14 15:57:44 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p(t_map *map)
{
	map->p_i = 0;
	while (map->map_m[map->p_i])
	{
		map->p_j = 0;
		while (map->map_m[map->p_i][map->p_j] &&
			map->map_m[map->p_i][map->p_j] != '\n')
		{
			if (map->map_m[map->p_i][map->p_j] == 'P')
				return ;
			map->p_j++;
		}
		map->p_i++;
	}
}

int	check_next_tile(t_map *data, char direction, char tile)
{
	if ((direction == 2 && data->map_m[data->p_i][data->p_j + 1] == tile)
		|| (direction == 0 && data->map_m[data->p_i][data->p_j - 1] == tile)
		|| (direction == 1 && data->map_m[data->p_i + 1][data->p_j] == tile)
		|| (direction == 13 && data->map_m[data->p_i - 1][data->p_j] == tile)
		)
		return (0);
	else
		return (1);
}

void	collect_coins(t_map *data, char direction)
{
	if ((direction == 2 && data->map_m[data->p_i][data->p_j + 1] == 'C')
		|| (direction == 0 && data->map_m[data->p_i][data->p_j - 1] == 'C')
		|| (direction == 1 && data->map_m[data->p_i + 1][data->p_j] == 'C')
		|| (direction == 13 && data->map_m[data->p_i - 1][data->p_j] == 'C'))
		data->collected++;
}

void	move_player(t_map *data, char direction)
{
	if (check_next_tile(data, direction, '1') == 0
		|| (data->can_exit == 0
			&& check_next_tile(data, direction, 'E') == 0))
		return ;
	data->steps_count++;
	collect_coins(data, direction);
	if (data->collected == data->collect)
		data->can_exit = 1;
	data->map_m[data->p_i][data->p_j] = '0';
	if (direction == 2)
		data->p_j++;
	else if (direction == 0)
		data->p_j--;
	else if (direction == 1)
		data->p_i++;
	else if (direction == 13)
		data->p_i--;
	printf("Moves counter : %d\n", data->steps_count);
	if (data->can_exit == 1 && data->map_m[data->p_i][data->p_j] == 'E')
		win_game(data);
	data->map_m[data->p_i][data->p_j] = 'P';
}

void	win_game(t_map *data)
{
	if (data->can_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		write(1, "You win\nMake a wish\n", 20);
		exit(1);
	}
}
