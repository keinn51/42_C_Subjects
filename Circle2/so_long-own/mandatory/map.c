/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:06:05 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/28 11:37:05 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail.\n");
	line = get_next_line(fd);
	if (!line)
		print_err("File read fail.\n");
	game->hgt = 0;
	game->walk_cnt = 0;
	game->wid = ft_strlen(line) - 1;
	game->map_line = ft_strdup_before_newline(line);
	free(line);
	line = "empty";
	while (line)
	{
		game->hgt++;
		line = get_next_line(fd);
		if (line)
			game->map_line = ft_strjoin_before_newline(game->map_line, line);
	}
	close(fd);
}

void	check_wall_surrounded(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->map_line))
	{
		if (i < game->wid)
		{
			if (game->map_line[i] != '1')
				print_err("Map must be close surrounded by walls.\n");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->map_line[i] != '1')
				print_err("Map must be surrounded by walls.\n");
		}
		else if (i > ft_strlen(game->map_line) - game->wid)
		{
			if (game->map_line[i] != '1')
				print_err("Map must be surrounded by walls.\n");
		}
		i++;
	}
}

void	check_wrong_arg(t_game *game)
{
	size_t	i;
	char	arg;

	i = 0;
	while (i < ft_strlen(game->map_line))
	{
		arg = game->map_line[i];
		if (arg != '0' && arg != '1' && arg != 'C' && arg != 'E' && arg != 'P')
			print_err("Map has wrong argument.\n");
		i++;
	}
}

void	check_no_arg(t_game *game)
{
	size_t	i;
	int		e_cnt;
	int		p_cnt;

	i = 0;
	e_cnt = 0;
	p_cnt = 0;
	while (i < ft_strlen(game->map_line))
	{
		if (game->map_line[i] == 'E')
			e_cnt++;
		else if (game->map_line[i] == 'P')
			p_cnt++;
		else if (game->map_line[i] == 'C')
			game->clt_sum++;
		i++;
	}
	if (e_cnt == 0)
		print_err("Map must have at least one exit.\n");
	if (game->clt_sum == 0)
		print_err("Map must have at least one collectible.\n");
	if (p_cnt != 1)
		print_err("Map must have one starting position.\n");
}

void	check_map(t_game *game)
{
	if (game->hgt * game->wid > 9223372036854775807)
		print_err("Map is too big.\n");
	if (game->hgt * game->wid != ft_strlen(game->map_line))
		print_err("Map must be rectangular.\n");
	game->clt_sum = 0;
	game->clt_cnt = 0;
	check_wall_surrounded(game);
	check_wrong_arg(game);
	check_no_arg(game);
}
