/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:41:11 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/25 06:50:24 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* menu_d -> menu default
* menu_p -> menu_default button play
* menu_q -> menu_default button option
* menu_o -> menu_default button quit
*/

void	imgs_load_menu(t_master *s_m)
{
	int	w;
	int	h;

	w = 1920;
	h = 1080;
	s_m->menu.menu_d = mlx_xpm_file_to_image(s_m->mlx, MENU_1, &w, &h);
	s_m->menu.menu_p = mlx_xpm_file_to_image(s_m->mlx, MENU_2, &w, &h);
	s_m->menu.menu_o = mlx_xpm_file_to_image(s_m->mlx, MENU_3, &w, &h);
	s_m->menu.menu_q = mlx_xpm_file_to_image(s_m->mlx, MENU_4, &w, &h);
	w = 1024;
	s_m->EA = mlx_xpm_file_to_image(s_m->mlx, s_m->map.EA, &w, &w);
	s_m->SO = mlx_xpm_file_to_image(s_m->mlx, s_m->map.SO, &w, &w);
	s_m->NO = mlx_xpm_file_to_image(s_m->mlx, s_m->map.NO, &w, &w);
	s_m->WE = mlx_xpm_file_to_image(s_m->mlx, s_m->map.WE, &w, &w);
}
