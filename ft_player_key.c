/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:20 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/06 12:19:46 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
? Ft_press(int key) est une fonction lorsqu'on appuis sur 
? la "key" la valeur sera soit 1 ou 0
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
* M : 109
*/

int	ft_press(int key)
{
	if (key)
		return (0);
	else
		return (1);
}

void	ft_mouse_play(int button, int x, int y, t_master *s_m)
{
	ft_printf("ok\n");
}

void	ft_key_player(int key, t_master *s_m)
{
	if (key == 109)
		s_m->minimap = ft_press(s_m->minimap);
	if (key == 104)
		s_m->help = ft_press(s_m->help);
	if (key == 199)
		s_m->map.map[3][3] = 'P';
}
