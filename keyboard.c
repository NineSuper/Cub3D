/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:31:48 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 23:25:11 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
		if (s_m->menu.choose == 3)
			ft_exit_menu(s_m);
	}
}

void	ft_mouse_menu(int x, int y, t_master *s_m)
{
	if (s_m->width < 1920)
		ft_mac_mouse_menu(x, y, s_m);
	else if (x >= 863 && x <= 1128 && y >= 359 && y <= 443)
		ft_play(s_m);
	else if (x >= 868 && x <= 1123 && y >= 490 && y <= 571)
		ft_printf("option\n");
	else if (x >= 849 && x <= 1123 && y >= 611 && y <= 691)
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
	if (s_m->screen == 5)
		ft_mouse_play(button, x, y, s_m);
	return (0);
}

int	deal_key(int key, t_master *s_m)
{
	if (key == 65307)
		ft_exit_menu(s_m);
	if (s_m->screen == 1)
		ft_key_menu(key, s_m);
	if (s_m->screen == 5)
		ft_key_player(key, s_m);
	return (0);
}
