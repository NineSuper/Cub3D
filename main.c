/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:29 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/06 13:27:04 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Check toutes les map : ft_check_map.c -> return (1) si ERROR
* Faire un menu : ft_menu.c -> return (*map)
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
	char	*map;

	s_m = ft_calloc(sizeof(t_master), 1);
	// ? check_map avant
	map = ft_menu(s_m);
	mlx_loop(s_m->mlx);
}
