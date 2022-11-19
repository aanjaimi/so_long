/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:49:31 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 13:35:49 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	variables_map(t_map *map, char *file)
{
	map->steps_count = 0;
	map->win_height = map_linecount(map, file) * IMG_SIZE;
	map->win_width = (count_line(map->map_m[0]) - 1) * IMG_SIZE;
	map->img_height = IMG_SIZE;
	map->img_width = IMG_SIZE;
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		msg_error("You must give me one input");
	map = (t_map *) malloc(sizeof(t_map));
	map->map_m = check_all(map, av[1]);
	find_p(map);
	variables_map(map, av[1]);
	init_win(map, av[1]);
	init_img(map);
	render(map);
	loop_images(map);
	destroy_images(map);
	free(map->mlx);
	if (map->map_m)
		ft_free(map->map_m);
}
