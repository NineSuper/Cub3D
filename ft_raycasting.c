/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/12 13:39:12 by tde-los-         ###   ########.fr       */
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
				img_pix_put(&s_m->img, x, y, s_m->map.c_c);
			else
				img_pix_put(&s_m->img, x, y, s_m->map.c_f);
		}
	}
}

void	ft_hud(t_master *s_m)
{
	put_img_to_img(s_m->img, s_m->cursor, s_m->m_x, s_m->m_y);
	if (WIDTH != 1920)
		return (ft_mac_hud(s_m));
	put_img_to_img(s_m->img, s_m->player.cross, (WIDTH / 2) - 64, \
		(HEIGHT / 2) - 64);
}

void	ft_raycast(t_master *s_m, char **map)
{
	s_m->img = new_img(WIDTH, HEIGHT, s_m);
	ft_skyflor(s_m);
	ft_minimap(s_m, s_m->map.map + s_m->map.len);
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
}
