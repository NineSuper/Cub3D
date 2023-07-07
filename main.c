/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:29 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/07 16:23:01 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Check toutes les map : ft_check_map.c -> return (1) si ERROR
* Faire un menu : ft_menu.c -> change map dans t_m->map.map
* Faire le ray-casting : ft_raycast.c
? Mettre des textures sur les murs
? Faire Bouger la camera
? Faire Bouger le Joueur
? Collision avec les murs
? Minimap
? Systeme de porte (ouverture/fermeture)
*/

int	main(void)
{
	t_master	*s_m;

	s_m = ft_calloc(sizeof(t_master), 1);
	// ? check_map avant
	ft_menu(s_m);
	mlx_key_hook(s_m->win, deal_key, s_m);
	mlx_loop(s_m->mlx);
}
