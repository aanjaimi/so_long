/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:42:24 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:47 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_inside(t_map	*map)
{
	map->i = 0;
	while (map->map_m[map->i])
	{
		map->j = 0;
		while (map->map_m[map->i][map->j] != '\n'
			&& map->map_m[map->i][map->j] != '\0')
		{
			if (map->map_m[map->i][map->j] == 'P'
				|| map->map_m[map->i][map->j] == 'C'
					|| map->map_m[map->i][map->j] == 'E'
						|| map->map_m[map->i][map->j] == '0'
							|| map->map_m[map->i][map->j] == '1')
				map->j++;
			else
				return (0);
		}
		map->i++;
	}
	return (1);
}

char	**check_rl(t_map	*check, char *file)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	check->map_m = check_wall(check, file);
	check->count = count_line(check->map_m[i]) - 1;
	while (check->map_m[i])
	{
		if (check->map_m[i][j] != '1'
			|| check->map_m[i][check->count - 1] != '1')
			msg_error("Invalid map\nMap must be surrounded by walls");
		i++;
	}
	return (check->map_m);
}

char	**check_map(t_map	*check, char *file)
{
	int	i;

	i = 0;
	check->map_m = read_map(check, file);
	check->count = count_line(check->map_m[i]);
	i++;
	while (check->map_m[i + 1])
	{
		if (check->count == count_line(check->map_m[i]))
			i++;
		else
			msg_error("Invalid map\nMap must be rectangular");
	}
	if (check->count != count_line(check->map_m[i]) + 1)
		msg_error("Invalid map\nMap must be rectangular");
	return (check->map_m);
}

char	**check_wall(t_map	*check, char *file)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	check->map_m = check_map(check, file);
	check->count = count_line(check->map_m[i]) - 1;
	while (check->map_m[k])
		k++;
	while (check->count--)
	{
		if (check->map_m[i][j++] != '1')
			msg_error("Invalid map\nMap must be surrounded by walls");
	}
	j = 0;
	while (check->map_m[k - 1][j])
	{
		if (check->map_m[k - 1][j++] != '1')
			msg_error("Invalid map\nMap must be surrounded by walls");
	}
	return (check->map_m);
}

int	check_double(t_map	*map)
{
	map->i = 0;
	map->player = 0;
	map->exit = 0;
	map->collect = 0;
	while (map->map_m[map->i])
	{
		map->j = 0;
		while (map->map_m[map->i][map->j] != '\0'
			&& map->map_m[map->i][map->j] != '\n')
		{
			if (map->map_m[map->i][map->j] == 'P')
				map->player++;
			else if (map->map_m[map->i][map->j] == 'C')
				map->collect++;
			else if (map->map_m[map->i][map->j] == 'E')
				map->exit++;
			map->j++;
		}
		map->i++;
	}
	if (map->player != 1 || map->collect == 0 || map->exit == 0)
		return (0);
	return (1);
}
