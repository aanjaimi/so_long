/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:41:45 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 11:53:02 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(char *file)
{
	char	c;
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		msg_error("Can't open file");
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret <= 0)
			break ;
		if (!ft_strchr("01PEC\n", c) || c == 0)
			return (-1);
	}
	close(fd);
	return (0);
}

char	**check_all(t_map	*check, char *file)
{
	if (!(check_extension(file)))
		msg_error("Invalid map\nWrong extension");
	if (check_extension(file) == -1)
		msg_error("Invalid map\nFile not exist");
	if (check_chars(file) == -1)
		msg_error("Invalid map\nWrong characters");
	check->map_m = check_rl(check, file);
	if (!(check_double(check) || !(check_inside(check))))
		msg_error("Invalid map\nMultiple characters");
	return (check->map_m);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}

void	free_str(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
