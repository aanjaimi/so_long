/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:42:00 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/14 23:53:47 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_extension(char *map)
{
	int	fd;
	int	len;

	len = 0;
	len = count_line(map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	close (fd);
	if (map[len - 4] == '.' && map[len - 3] == 'b' && map[len - 2] == 'e' && \
	map[len - 1] == 'r')
		return (1);
	return (0);
}
