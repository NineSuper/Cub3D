/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strafe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:29:20 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/10 18:56:47 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_key_a(t_master *s_m, char **map)
{
	t_player	*player;

	player = &s_m->player;
	if (map[(int)player->posy] \
		[(int)(player->posx + (player->diry / 10))] != '1' \
		&& map[(int)player->posy] \
		[(int)(player->posx + (player->diry / 10))] != 'D')
		s_m->player.posx += s_m->player.diry / 10;
	if (map[(int)(s_m->player.posy - (s_m->player.dirx / 10))] \
		[(int)(player->posx)] != '1' \
		&& map[(int)(s_m->player.posy - (s_m->player.dirx / 10))] \
		[(int)(player->posx)] != 'D')
		s_m->player.posy -= s_m->player.dirx / 10;
}

void	ft_key_d(t_master *s_m, char **map)
{
	t_player	*player;

	player = &s_m->player;
	if (map[(int)player->posy] \
		[(int)(player->posx - (player->diry / 10))] != '1' \
		&& map[(int)player->posy] \
		[(int)(player->posx - (player->diry / 10))] != 'D')
		s_m->player.posx -= s_m->player.diry / 10;
	if (map[(int)(s_m->player.posy + (s_m->player.dirx / 10))] \
		[(int)(player->posx)] != '1' \
		&& map[(int)(s_m->player.posy + (s_m->player.dirx / 10))] \
		[(int)(player->posx)] != 'D')
		s_m->player.posy += s_m->player.dirx / 10;
}

void	ft_other_key(int key, t_master *s_m, char **map)
{
	if (key == 101)
		ft_open_door(s_m, map);
	if (key == 104)
		s_m->help = ft_press(s_m->help);
	if (key == 97)
		ft_key_a(s_m, map);
	if (key == 100)
		ft_key_d(s_m, map);
}
