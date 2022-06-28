/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:17:37 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/27 21:18:26 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *g, char *map)
{
	g->mlx = mlx_init();
	if (!(g->mlx))
		print_err("Mlx Start Fail.\n");
	g->img = init_image(g->mlx);
	read_map(map, g);
	check_map(g);
	g->win = mlx_new_window(g->mlx, g->wid * 64, g->hgt * 64, "so_long");
	set_image(g);
}

int	clear_game(t_game *game)
{
	game->walk_cnt++;
	printf("%s %d%s\n", "Congratulations! You have", game->walk_cnt, "steps.");
	exit(0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
