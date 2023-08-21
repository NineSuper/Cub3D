/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/08/21 10:32:07 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Si 'N' : angle 0°
* Si 'S' : angle 180°
* Si 'E' : angle 90°
* Si 'O' : angle 270°
? Faire le ray-casting : ft_raycast.c
? Savoir l'orientation du joueur
? Projeter un mur
? Mettre la couleur sur le ciel/sol
? Mettre des textures sur les murs
? Faire Bouger la camera
? Faire Bouger le Joueur
? Collision avec les murs
? Minimap
? Systeme de porte (ouverture/fermeture)
! width / X = largeur
! height / Y = Hauteur
*/

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
				mlx_pixel_put(s_m->mlx, s_m->win, x, y, s_m->map.c_c);
			else
				mlx_pixel_put(s_m->mlx, s_m->win, x, y, s_m->map.c_f);
		}
	}
}


void	ft_raycast(t_master *s_m, char **map)
{
	ft_skyflor(s_m);
	ft_minimap(s_m, s_m->map.map + s_m->map.len);
}
