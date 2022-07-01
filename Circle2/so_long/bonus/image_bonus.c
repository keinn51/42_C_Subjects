/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:06:14 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/27 21:19:51 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	init_image(void *mlx)
{
	t_img	nd;
	int		wid;
	int		hgt;

	nd.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &wid, &hgt);
	nd.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hgt);
	nd.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &wid, &hgt);
	nd.collec = mlx_xpm_file_to_image(mlx, "./images/collec.xpm", &wid, &hgt);
	nd.wait = mlx_xpm_file_to_image(mlx, "./images/wait.xpm", &wid, &hgt);
	nd.exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &wid, &hgt);
	if (!(nd.land) || !(nd.wall) || !(nd.player) || !(nd.collec)
		|| !(nd.wait) || !(nd.exit))
		print_err("Fail to load images\n");
	return (nd);
}

void	put_image(t_game *g, int w, int h)
{
	if (g->map_line[h * g->wid + w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	else if (g->map_line[h * g->wid + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.collec, w * 64, h * 64);
	else if (g->map_line[h * g->wid + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 64, h * 64);
	else if (g->map_line[h * g->wid + w] == 'E' && g->clt_sum == g->clt_cnt)
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 64, h * 64);
	else if (g->map_line[h * g->wid + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wait, w * 64, h * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
}

void	set_image(t_game *game)
{
	size_t	hgt;
	size_t	wid;

	hgt = 0;
	while (hgt < game->hgt)
	{
		wid = 0;
		while (wid < game->wid)
		{
			put_image(game, wid, hgt);
			wid++;
		}
		hgt++;
	}
	show_moves(game);
}
