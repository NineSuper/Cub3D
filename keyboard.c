/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:31:48 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/20 22:32:09 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* 65361 : gauche
* 65363 : droite
* 65362 : haut
* 65364 : bas
* 65293 : entrer
* 65307 : echap
* W : 119
* Q : 97
* S : 115 
* D : 100
* Key hook en fonction de l'ecran sur lequels en se trouve :

! 		s_m->screen = 1 : menu
? fleche du haut : imgs X++
? fleche du bas : imgs X--
? Entrer : selectionner X element

* detecter la souris ou elle se trouve :
? si elle se trouver sur : play image->menu->play
?						 : option image->menu->option
?						 : quit image->menu->quit
? sinon : image->menu->default

! si click souris : si souris sur element X alors : image->X

!	s_m->screen = 2 : option
*/

void	ft_key_menu(int key, t_master *s_m)
{
	if (key == 65362)
		if (s_m->menu.choose == 1)
			s_m->menu.choose = 3;
		else
			s_m->menu.choose--;
	if (key == 65364)
		s_m->menu.choose++;
	if (s_m->menu.choose > 3 || s_m->menu.choose < 1)
		s_m->menu.choose = 1;
	ft_get_menu(s_m->menu.choose, s_m);
	if (key == 65293)
	{
	/*! ENTRER alors aller dans le menu suivant
	 	if (s_m->menu.choose == 1)
	 	 	? play
		if (s_m->menu.choose == 2)*/
	 	 	//? option
		if (s_m->menu.choose == 3)
			ft_exit_menu(s_m);
	}
}

int	deal_key(int key, t_master *s_m)
{
	if (s_m->screen == 1)
		ft_key_menu(key, s_m);
	else
		ft_printf("no menu\n");
	//ft_printf("KEY : [%d]\n", key);
}