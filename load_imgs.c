/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:41:11 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 23:12:43 by tde-los-         ###   ########.fr       */
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

t_imgs	ft_resize_load(t_master *s_m, t_imgs src)
{
	t_imgs	temp;

	if (src.h != 512 || src.w != 512)
	{
		temp = src;
		temp = ft_img_resize(s_m, src, 512, 512);
		ft_destroy_img(s_m->mlx, src.m_img);
		return (temp);
	}
	return (src);
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
	s_m->door = new_file_img(DOOR, s_m);
	s_m->exit = new_file_img(EXIT, s_m);
	s_m->door = ft_resize_load(s_m, s_m->door);
	s_m->exit = ft_resize_load(s_m, s_m->exit);
	s_m->ea = ft_resize_load(s_m, s_m->ea);
	s_m->no = ft_resize_load(s_m, s_m->no);
	s_m->we = ft_resize_load(s_m, s_m->we);
	s_m->so = ft_resize_load(s_m, s_m->so);
}
