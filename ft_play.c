/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:45:53 by tde-los-          #+#    #+#             */
/*   Updated: 2023/10/19 09:34:37 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_skyflor(t_master *s_m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < s_m->height)
	{
		x = -1;
		while (++x < s_m->width)
		{
			if (y < s_m->height / 2)
				img_pix_put(&s_m->skyfloor, x, y, s_m->map.c_c);
			else
				img_pix_put(&s_m->skyfloor, x, y, s_m->map.c_f);
		}
	}
}

void	ft_player_pos(t_master *s_m, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				s_m->player.x = x;
				s_m->player.y = y;
			}
		}
	}
}

void	ft_play(t_master *s_m)
{
	ft_loader_b(s_m, s_m->mlx, s_m->win);
	ft_skyflor(s_m);
	if (!s_m->player.x || !s_m->player.y)
	 	ft_player_pos(s_m, s_m->map.map + s_m->map.len);
	s_m->screen = 5;
}
