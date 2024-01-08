/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:20 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/08 12:52:54 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

/*
? Ft_press(int key) est une fonction lorsqu'on appuis sur
? la "key" la valeur sera soit 1 ou 0
* 65361 : gauche
* 65363 : droite
* 65362 : haut
* 65364 : bas
* 65293 : entrer
* 65307 : echap
* 1 Click gauche
* 3 Click Droite
* 4 Molette haut
* 5 Molette bas
* W : 119
* Q : 97
* S : 115
* D : 100
* M : 109

todo Collision avec les murs
todo (Bonus) Ouvrir des portes (pas obliger de le faire)
? s_m->map.map[][] + s_m->map.len;
*/

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
}

int	ft_can_moove_y(t_player *player, char **map, int i)
{
	if (map[(int)(player->posy + (player->diry / 10))][(int)(player->posx)] == '1' && i)
		return (1);
	else if (map[(int)(player->posy - (player->diry / 10))][(int)(player->posx)] == '1')
		return (1);
	return (0);
}

int	ft_can_moove_x(t_player *player, char **map, int i)
{
	if (map[(int)player->posy][(int)(player->posx + (player->dirx / 10))] == '1' && i)
		return (1);
	else if (map[(int)player->posy][(int)(player->posx - (player->dirx / 10))] == '1')
		return (1);
	return (0);
}


void	ft_key_player(int key, t_master *s_m)
{
	t_player	*player;
	char **map = s_m->map.map + s_m->map.len;

	player = &s_m->player;
	if (key == 109)
		s_m->minimap = ft_press(s_m->minimap);
	if (key == 104)
		s_m->help = ft_press(s_m->help);
	if (key == 119)
	{
		if (!ft_can_moove_x(player, map, 1))
			player->posx += player->dirx / 10;
		if (!ft_can_moove_y(player, map, 1))
			player->posy += player->diry / 10;
	}
	if (key == 115)
	{
		if (!ft_can_moove_x(player, map, 0))
			player->posx -= player->dirx / 10;
		if (!ft_can_moove_y(player, map, 0))
			player->posy -= player->diry / 10;
	}
	if (key == 97)
		ft_cam(97, player, 0.10);
	if (key == 100)
		ft_cam(100, player, 0.10);
}
