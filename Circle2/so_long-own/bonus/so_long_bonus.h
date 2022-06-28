/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:05:56 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/27 23:32:56 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "./get_next_line_bonus.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*player;
	void	*collec;
	void	*land;
	void	*wait;
	void	*exit;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	size_t	wid;
	size_t	hgt;
	char	*map_line;
	int		clt_sum;
	int		clt_cnt;
	int		walk_cnt;
}				t_game;

char	*ft_strdup_before_newline(char *str);
char	*ft_strjoin_before_newline(char *s1, char *s2);
t_img	init_image(void *mlx);
void	set_image(t_game *game);
void	read_map(char *filename, t_game *game);
void	check_map(t_game *game);
int		clear_game(t_game *game);
void	show_moves(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	print_err(char *message);
int		exit_game(t_game *game);
void	init_game(t_game *g, char *map);
char	*ft_itoa(int n);

#endif