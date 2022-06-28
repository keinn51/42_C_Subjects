/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:06:10 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/27 20:29:05 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	show_moves(t_game *game)
{
	char	*step_str;

	step_str = ft_itoa(game->walk_cnt);
	mlx_string_put(game->mlx, game->win,
		1 * 64, 1 * 64 + 20, 0xFF5733, "MOVES:");
	mlx_string_put(game->mlx, game->win,
		1 * 64 + 50, 1 * 64 + 20, 0xFF5733, step_str);
	free(step_str);
	step_str = NULL;
}

void	move_w(t_game *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i - g->wid] == 'C')
		g->clt_cnt++;
	if (g->map_line[i - g->wid] == 'E' && g->clt_sum == g->clt_cnt)
		clear_game(g);
	else if (g->map_line[i - g->wid] != '1' && g->map_line[i - g->wid] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i - g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		set_image(g);
	}
}

void	move_a(t_game *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i - 1] == 'C')
		g->clt_cnt++;
	if (g->map_line[i - 1] == 'E' && g->clt_sum == g->clt_cnt)
		clear_game(g);
	else if (g->map_line[i - 1] != '1' && g->map_line[i - 1] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i - 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		set_image(g);
	}
}

void	move_s(t_game *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i + g->wid] == 'C')
		g->clt_cnt++;
	if (g->map_line[i + g->wid] == 'E' && g->clt_sum == g->clt_cnt)
		clear_game(g);
	else if (g->map_line[i + g->wid] != '1' && g->map_line[i + g->wid] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i + g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		set_image(g);
	}
}

void	move_d(t_game *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i + 1] == 'C')
		g->clt_cnt++;
	if (g->map_line[i + 1] == 'E' && g->clt_sum == g->clt_cnt)
		clear_game(g);
	else if (g->map_line[i + 1] != '1' && g->map_line[i + 1] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i + 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		set_image(g);
	}
}
