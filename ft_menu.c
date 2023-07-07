/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:39:28 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/07 10:34:48 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Faire un menu lorsque le jeu est lance avec :
? New Game 
? Control
? Quit

! New Game :
* Map1
* Map2
* Map3
* Retour

! Control
* Avancer
* Reculer
* Gauche
* Droite
* Retour

int s_m->screen	
			= 1 menu;
			= 2 map;
			= 3 option;
			= 4 chargement;
			= 5 Jeu;

? lorsque le joueur choisi une map, return (*map) | "exit" si 'Quit'
*/

char	*ft_menu(t_master *s_m)
{
	s_m->mlx = mlx_init();
	s_m->width = 1920 * 1.5;
	s_m->height = 1080 * 1.5;
	s_m->win = mlx_new_window(s_m->mlx, s_m->width, s_m->height, "Cub3D");
	ft_loader_b(s_m, s_m->mlx, s_m->win);
	s_m->screen = 1;
}
