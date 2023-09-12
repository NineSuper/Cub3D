/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:19:29 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/12 11:50:37 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_mac_hud(t_master *s_m)
{
	put_img_to_img(s_m->img, s_m->player.cross, (WIDTH / 2) - 32, \
		(HEIGHT / 2) - 32);
}

void	ft_mac_mouse_menu(int x, int y, t_master *s_m)
{
	if (x >= 414 && x <= 542 && y >= 216 && y <= 252)
		ft_play(s_m);
	if (x >= 402 && x <= 544 && y >= 267 && y <= 310)
		printf("option\n");
	if (x >= 414 && x <= 545 && y >= 341 && y <= 386)
		ft_exit_menu(s_m);
}
