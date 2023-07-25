/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:31:48 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/25 05:43:24 by tde-los-         ###   ########.fr       */
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
* 1 Click gauche
* 3 Click Droite
* 4 Molette haut
* 5 Molette bas
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
	{
		if (s_m->menu.choose == 1)
			s_m->menu.choose = 3;
		else
			s_m->menu.choose--;
	}
	if (key == 65364)
		s_m->menu.choose++;
	if (s_m->menu.choose > 3 || s_m->menu.choose < 1)
		s_m->menu.choose = 1;
	ft_get_menu(s_m->menu.choose, s_m);
	if (key == 65293)
	{
		if (s_m->menu.choose == 1)
			ft_play(s_m);
		/* 
		if (s_m->menu.choose == 2)
	 	 	? option
		*/
		if (s_m->menu.choose == 3)
			ft_exit_menu(s_m);
	}
}

void	ft_mouse_menu(int x, int y, t_master *s_m)
{
	if (x >= 863 && x <= 1128 && y >= 359 && y <= 443)
		ft_play(s_m);
	if (x >= 868 && x <= 1123 && y >= 490 && y <= 571)
		printf("option\n");
	if (x >= 849 && x <= 1123 && y >= 611 && y <= 691)
		ft_exit_menu(s_m);
}

int	ft_mouse(int button, int x, int y, void *data)
{
	t_master	*s_m;

	s_m = data;
	s_m->m_x = x;
	s_m->m_y = y;
	if (s_m->screen == 1)
		ft_mouse_menu(s_m->m_x, s_m->m_y, s_m);
}

int	deal_key(int key, t_master *s_m)
{
	if (key == 65307)
		ft_exit_menu(s_m);
	if (s_m->screen == 1)
		ft_key_menu(key, s_m);
	else
		ft_printf("s_m->screen: %d\n", s_m->screen);
	//ft_printf("KEY : [%d]\n", key);
}
