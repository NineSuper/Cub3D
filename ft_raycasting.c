/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/17 15:28:55 by tde-los-         ###   ########.fr       */
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

char	**ft_backmap(t_master *s_m, char **map)
{
	char	**temp_map;
	int		i;
	int		j;
	int		x;

	temp_map = ft_calloc(27, sizeof(char *) + 1);
	map += s_m->map.len;
	map[s_m->player.y][s_m->player.x] = 'P';
	i = s_m->player.y - 3;
	if (i < 0)
		i = 0;
	j = 0;
	x = s_m->player.x - 6;
	if (x < 0)
		x = 0;
	while (map[i] && i < s_m->player.y + 5)
		temp_map[j++] = ft_substr(map[i++], x, x + 8);
	return (temp_map);
}

void	ft_raycast(t_master *s_m, char **map)
{
	if (s_m->img.m_img)
		mlx_destroy_image(s_m->mlx, s_m->img.m_img);
	s_m->img = new_img(WIDTH, HEIGHT, s_m);
	put_img_to_img(s_m->img, s_m->skyfloor, 0, 0);

	//ft_rplace(s_m, s_m->no, s_m->img, (t_coords){30, 80, 800, 800});
	
	ft_minimap(s_m, ft_backmap(s_m, s_m->map.map));
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
}
