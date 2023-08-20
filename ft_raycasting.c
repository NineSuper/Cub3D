/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/08/20 17:06:03 by tde-los-         ###   ########.fr       */
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
*/

void	ft_raycast(t_master *s_m, char **map)
{
	ft_printf("dir : %d\n", s_m->player.dir); // ? Debug
	ft_minimap(s_m, map);
}
