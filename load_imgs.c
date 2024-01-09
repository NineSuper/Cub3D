/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:41:11 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 16:16:28 by tde-los-         ###   ########.fr       */
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

void	load_hud(t_master *s_m)
{
	s_m->skyfloor = new_img(WIDTH, HEIGHT, s_m);
	s_m->player.cross = new_file_img(CROSS, s_m);
	s_m->cursor = new_file_img(CURSOR, s_m);
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
	load_hud(s_m);
	s_m->ea = new_file_img(s_m->map.ea + 1, s_m);
	s_m->so = new_file_img(s_m->map.so + 1, s_m);
	s_m->no = new_file_img(s_m->map.no + 1, s_m);
	s_m->we = new_file_img(s_m->map.we + 1, s_m);
	s_m->ea = ft_img_resize(s_m, s_m->ea, 512, 512);
	s_m->no = ft_img_resize(s_m, s_m->no, 512, 512);
	s_m->we = ft_img_resize(s_m, s_m->we, 512, 512);
	s_m->so = ft_img_resize(s_m, s_m->so, 512, 512);
}
