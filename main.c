/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:29 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/08 22:29:22 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Check toutes les map : ft_check_map.c -> exit (0) si ERROR
* Faire un menu : ft_menu.c -> change map dans t_m->map.map
* Faire le ray-casting : ft_raycast.c
? Mettre des textures sur les murs
* Faire Bouger la camera
* Faire Bouger le Joueur
? Collision avec les murs
* Minimap
? Systeme de porte (ouverture/fermeture)
int s_m->screen
			= 1 menu;
			= 2 map;
			= 3 option;
			= 4 chargement;
			= 5 Jeu;

todo : ft_player_key.c
todo : ft_raycasting.c (ft_math.c : (voir DDA))
todo : Vérifier la norme et mettre les flags
todo : enlever les commentaires à la fin
*/

int	ft_loop(t_master *s_m)
{
	mlx_hook(s_m->win, 17, 1L << 5, ft_exit_menu, s_m);
	mlx_mouse_get_pos(s_m->mlx, s_m->win, &s_m->m_x, &s_m->m_y);
	if (s_m->screen == 5)
	{
		ft_raycast(s_m);
		if (s_m->m_x > (WIDTH / 2) + 300 && ft_onscreen(s_m))
			ft_mouse_play(7, 0, 0, s_m);
		if (s_m->m_x < (WIDTH / 2) - 300 && ft_onscreen(s_m))
			ft_mouse_play(6, 0, 0, s_m);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_master	*s_m;

	if (!argv[1] || argc != 2)
		return (ft_printf("%s%s\n\033[00m", C_RED, ARGC), 0);
	s_m = ft_calloc(sizeof(t_master), 22);
	ft_check_map(s_m, argv[1]);
	mlx_mouse_hook(s_m->win, ft_mouse, (void *) s_m);
	mlx_hook(s_m->win, 2, 1L << 0, deal_key, s_m);
	mlx_loop_hook(s_m->mlx, ft_loop, (void *) s_m);
	mlx_loop(s_m->mlx);
}
