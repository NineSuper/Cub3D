/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:20 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:50 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

int	ft_press(int key)
{
	if (key)
		return (0);
	else
		return (1);
}

void	ft_mouse_play(int button, int x, int y, t_master *s_m)
{
	if (button == 7)
		ft_cam(100, &s_m->player, 0.06);
	if (button == 6)
		ft_cam(97, &s_m->player, 0.06);
	(void)x;
	(void)y;
}

int	ft_can_moove_y(t_player *player, char **map, int i)
{
	if (map[(int)(player->posy + (player->diry / 10))] \
		[(int)(player->posx)] == '1' && i)
		return (1);
	else if (map[(int)(player->posy - (player->diry / 10))] \
		[(int)(player->posx)] == '1')
		return (1);
	return (0);
}

int	ft_can_moove_x(t_player *player, char **map, int i)
{
	if (map[(int)player->posy] \
		[(int)(player->posx + (player->dirx / 10))] == '1' && i)
		return (1);
	else if (map[(int)player->posy] \
		[(int)(player->posx - (player->dirx / 10))] == '1')
		return (1);
	return (0);
}

void	ft_key_player(int key, t_master *s_m)
{
	char		**map;

	map = s_m->map.map + s_m->map.len;
	if (key == 109)
		s_m->minimap = ft_press(s_m->minimap);
	if (key == 104)
		s_m->help = ft_press(s_m->help);
	if (key == 119)
	{
		if (!ft_can_moove_x(&s_m->player, map, 1))
			s_m->player.posx += s_m->player.dirx / 10;
		if (!ft_can_moove_y(&s_m->player, map, 1))
			s_m->player.posy += s_m->player.diry / 10;
	}
	if (key == 115)
	{
		if (!ft_can_moove_x(&s_m->player, map, 0))
			s_m->player.posx -= s_m->player.dirx / 10;
		if (!ft_can_moove_y(&s_m->player, map, 0))
			s_m->player.posy -= s_m->player.diry / 10;
	}
	if (key == 97)
		ft_cam(97, &s_m->player, 0.10);
	if (key == 100)
		ft_cam(100, &s_m->player, 0.10);
}
