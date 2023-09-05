/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:25:03 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/05 20:38:03 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_text_mac(t_master *s_m)
{
	mlx_string_put(s_m->mlx, s_m->win, 4, 222, create_trgb(0, 0, 0, 255), "Extra Key");
	mlx_string_put(s_m->mlx, s_m->win, 4, 242, create_trgb(0, 0, 0, 255), "M: Map");
	mlx_string_put(s_m->mlx, s_m->win, 4, 262, create_trgb(0, 0, 0, 255), "ESC: Exit");
	mlx_string_put(s_m->mlx, s_m->win, 4, 282, create_trgb(0, 0, 0, 255), "SPACE: Shoot");
}

void	ft_text(t_master *s_m)
{
	if (s_m->width < 1920)
		ft_text_mac(s_m);
}