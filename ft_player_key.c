/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:20 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/23 09:55:47 by tde-los-         ###   ########.fr       */
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

/*
		! A REVOIR LORS DES DEPLACEMENTS DU JOUEUR
		* Deplacement joueur -> minimap [ok]
		? Deplacement joueur -> 3D [NON]
*/

void	ft_key_player(int key, t_master *s_m)
{
	double	rotSpeed = 0.09;
	t_player	*player;

	player = &s_m->player;
	if (key == 109)
		s_m->minimap = ft_press(s_m->minimap);
	if (key == 104)
		s_m->help = ft_press(s_m->help);
	if (key == 119)
	{
		s_m->player.posX += s_m->player.dirX / 10;
		s_m->player.posY += s_m->player.dirY / 10;
	}
	if (key == 115)
	{
		s_m->player.posX -= s_m->player.dirX / 10;
		s_m->player.posY -= s_m->player.dirY / 10;
	}
	if (key == 97)
	{
		double oldDirX = s_m->player.dirX;
		s_m->player.dirX = s_m->player.dirX * cos(-rotSpeed) - s_m->player.dirY * sin(-rotSpeed);
		s_m->player.dirY = oldDirX * sin(-rotSpeed) + s_m->player.dirY * cos(-rotSpeed);
		double oldPlaneX = s_m->player.planeX;
		s_m->player.planeX = s_m->player.planeX * cos(-rotSpeed) - s_m->player.planeY * sin(-rotSpeed);
		s_m->player.planeY = oldPlaneX * sin(-rotSpeed) + s_m->player.planeY * cos(-rotSpeed);
	}
	if (key == 100)
	{
		double oldDirX = s_m->player.dirX;
		s_m->player.dirX = s_m->player.dirX * cos(rotSpeed) - s_m->player.dirY * sin(rotSpeed);
		s_m->player.dirY = oldDirX * sin(rotSpeed) + s_m->player.dirY * cos(rotSpeed);
		double oldPlaneX = s_m->player.planeX;
		s_m->player.planeX = s_m->player.planeX * cos(rotSpeed) - s_m->player.planeY * sin(rotSpeed);
		s_m->player.planeY = oldPlaneX * sin(rotSpeed) + s_m->player.planeY * cos(rotSpeed);
	}
}
