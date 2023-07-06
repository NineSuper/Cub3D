/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:39:28 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/06 13:48:48 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Ecran noir avec ecrit 'Chargement des textures/maps' et un cercle qui tourne
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

? lorsque le joueur choisi une map, return (*map) | "exit" si 'Quit'
*/

char    *ft_menu(t_master *s_m)
{
    s_m->mlx = mlx_init();
    s_m->win = mlx_new_window(s_m->mlx, 1920, 1080, "Cub3D");
}