/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:41:11 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/11 14:07:40 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* menu_d -> menu default
* menu_p -> menu_default button play
* menu_q -> menu_default button option
* menu_o -> menu_default button quit
*/

void	imgs_load_mac(t_master *s_m)
{
	int	w;
	int	h;

	w = 1920 / 2;
	h = 1080 / 2;
	s_m->menu.menu_d = mlx_xpm_file_to_image(s_m->mlx, MENU_5, &w, &h);
	s_m->menu.menu_p = mlx_xpm_file_to_image(s_m->mlx, MENU_6, &w, &h);
	s_m->menu.menu_o = mlx_xpm_file_to_image(s_m->mlx, MENU_7, &w, &h);
	s_m->menu.menu_q = mlx_xpm_file_to_image(s_m->mlx, MENU_8, &w, &h);
}

void	imgs_load_menu(t_master *s_m)
{
	int	w;
	int	h;

	w = 1920;
	h = 1080;
	if (s_m->width < 1920)
		imgs_load_mac(s_m);
	else
	{
		s_m->menu.menu_d = mlx_xpm_file_to_image(s_m->mlx, MENU_1, &w, &h);
		s_m->menu.menu_p = mlx_xpm_file_to_image(s_m->mlx, MENU_2, &w, &h);
		s_m->menu.menu_o = mlx_xpm_file_to_image(s_m->mlx, MENU_3, &w, &h);
		s_m->menu.menu_q = mlx_xpm_file_to_image(s_m->mlx, MENU_4, &w, &h);
	}
	w = 32;
	s_m->player.cross = mlx_xpm_file_to_image(s_m->mlx, CROSS, &w, &w);
	w = 1024;
	s_m->ea = mlx_xpm_file_to_image(s_m->mlx, s_m->map.ea, &w, &w);
	s_m->so = mlx_xpm_file_to_image(s_m->mlx, s_m->map.so, &w, &w);
	s_m->no = mlx_xpm_file_to_image(s_m->mlx, s_m->map.no, &w, &w);
	s_m->we = mlx_xpm_file_to_image(s_m->mlx, s_m->map.we, &w, &w);
}
