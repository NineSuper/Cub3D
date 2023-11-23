/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:20 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/23 13:57:47 by tde-los-         ###   ########.fr       */
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
	ft_printf("ok\n");
}

void	ft_key_player(int key, t_master *s_m)
{
	double	rotSpeed = 0.11;
	t_player	*player;

	player = &s_m->player;
	if (key == 109)
	{
		printf("X : %f Y : %f\n", player->dirx, player->diry);
		s_m->minimap = ft_press(s_m->minimap);
	}
	if (key == 104)
		s_m->help = ft_press(s_m->help);
	if (key == 119)
	{
		player->posx += player->dirx / 10;
		player->posy += player->diry / 10;
	}
	if (key == 115)
	{
		player->posx -= player->dirx / 10;
		player->posy -= player->diry / 10;
	}
	if (key == 97)
	{
		double oldDirX = player->dirx;
		player->dirx = player->dirx * cos(-rotSpeed) - player->diry * sin(-rotSpeed);
		player->diry = oldDirX * sin(-rotSpeed) + player->diry * cos(-rotSpeed);

		double oldPlaneX = player->planex;
		player->planex = player->planex * cos(-rotSpeed) - player->planey * sin(-rotSpeed);
		player->planey = oldPlaneX * sin(-rotSpeed) + player->planey * cos(-rotSpeed);
	}

	if (key == 100)
	{
		double oldDirX = player->dirx;
		player->dirx = player->dirx * cos(rotSpeed) - player->diry * sin(rotSpeed);
		player->diry = oldDirX * sin(rotSpeed) + player->diry * cos(rotSpeed);

		double oldPlaneX = player->planex;
		player->planex = player->planex * cos(rotSpeed) - player->planey * sin(rotSpeed);
		player->planey = oldPlaneX * sin(rotSpeed) + player->planey * cos(rotSpeed);
	}
}
