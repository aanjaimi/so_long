/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:49:45 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/15 14:35:32 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define IMG_SIZE 50
# define A 0
# define D 2
# define S 13
# define W 1

typedef struct s_map
{
	char	**map_m;
	int		count;
	int		fd;
	int		i;
	int		j;
	int		k;
	char	*line;
	int		player;
	int		exit;
	int		collect;
	int		nothing;
	int		p_i;
	int		p_j;
	int		win_height;
	int		win_width;
	int		img_width;
	int		img_height;
	int		can_exit;
	int		steps_count;
	int		collected;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	void	*ground;
	void	*wall;
	void	*exit_;
	void	*player_;
	void	*coins;
}	t_map;

void		prt_map(char **file);
void		destroy_images(t_map *data);
void		loop_images(t_map *data);
void		*msg_error(char *msg);
int			check_extension(char *map);
int			map_linecount(t_map *data, char *file);
char		**alloc_columns(t_map *data, char *file);
char		**read_map(t_map *data, char *file);
int			count_line(char *str);
char		**check_map(t_map *data, char *file);
char		**check_wall(t_map *data, char *file);
int			check_double(t_map *data);
char		**check_all(t_map *data, char *file);
char		*ft_strchr(const char *s, int c);
int			check_inside(t_map *data);
char		**check_rl(t_map *data, char *file);
void		check_mlx(t_map *img);
void		find_p(t_map *map);
int			render(t_map *map);
void		variables_map(t_map *map, char *file);
void		init_win(t_map *map, char *file);
void		init_img(t_map *map);
void		ft_free(char **tab);
void		move_player(t_map *data, char direction);
int			check_next_tile(t_map *data, char direction, char tile);
void		collect_coins(t_map *data, char direction);
void		move_msg(t_map *data);
void		win_game(t_map *data);

#endif