/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:43:27 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 11:48:52 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_linecount(t_map	*check, char *file)
{
	check->fd = open(file, O_RDONLY);
	if (!check->fd)
		return (-1);
	check->line = get_next_line(check->fd);
	if (!check->line)
		msg_error("empty map!");
	if (!(ft_strchr(check->line, '1')))
		msg_error("invalid map");
	check->count = 1;
	while (1)
	{
		check->line = get_next_line(check->fd);
		if (!check->line)
			break ;
		check->count++;
	}
	close (check->fd);
	return (check->count);
}

char	**alloc_columns(t_map *check, char *file)
{
	check->count = map_linecount(check, file);
	if (check->count <= 0)
		return (msg_error("open or reading error..."));
	check->map_m = malloc(sizeof(char *) * check->count + 1);
	if (!check->map_m)
	{
		perror("Error");
		exit(1);
	}
	return (check->map_m);
}

char	**read_map(t_map *check, char *file)
{
	check->map_m = alloc_columns(check, file);
	if (check->map_m == NULL)
		return (NULL);
	check->fd = open(file, O_RDONLY);
	if (check->fd <= 0)
		msg_error("open or reading error...");
	check->i = 0;
	while (1)
	{
		check->map_m[check->i] = get_next_line(check->fd);
		if (!check->map_m[check->i])
			break ;
		check->i++;
	}
	check->map_m[check->i] = NULL;
	close(check->fd);
	return (check->map_m);
}
