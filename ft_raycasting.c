/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/17 12:38:40 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
Si 'N' : angle 0°
Si 'S' : angle 180°
Si 'E' : angle 90°
Si 'O' : angle 270°
? Savoir l'orientation du joueur
? Projeter un mur
* Mettre la couleur sur le ciel/sol
? Mettre des textures sur les murs
? Faire Bouger la camera
? Faire Bouger le Joueur
? Collision avec les murs
* Minimap
? Systeme de porte (ouverture/fermeture)
! width / X = largeur
! height / Y = Hauteur
*/

/*
	? put_img_to_img(s_m->img, s_m->cursor, s_m->m_x, s_m->m_y);
*/

void	ft_hud(t_master *s_m)
{
	if (WIDTH != 1920)
		return (ft_mac_hud(s_m));
	put_img_to_img(s_m->img, s_m->player.cross, (WIDTH / 2) - 64, \
		(HEIGHT / 2) - 64);
}

/*
* Faire une fonction qui va creer une map temporaire
? Elle prendra la position du joueur
todo 	Centrer le joueur
* x = 7;   y = 5;
? player.y - 6 < a > player.y + 6 =  13
? player.x - 5 < a > player.x + 5 =  11
todo  	free map_temp
* x = 15 y = 12
*/

void	ft_raycast(t_master *s_m, char **map)
{
	if (s_m->img.m_img)
		mlx_destroy_image(s_m->mlx, s_m->img.m_img);
	s_m->img = new_img(WIDTH, HEIGHT, s_m);
	put_img_to_img(s_m->img, s_m->skyfloor, 0, 0);

	ft_rplace(s_m, s_m->no, s_m->img, (t_coords){30, 80, 800, 800});
	
	ft_minimap(s_m, s_m->map.map + s_m->map.len);
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
}
