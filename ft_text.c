/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:25:03 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/05 20:39:17 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_text_mac(t_master *s_m)
{
	mlx_string_put(s_m->mlx, s_m->win, 4, 222, 0xFFFFFF, "Extra Key");
	mlx_string_put(s_m->mlx, s_m->win, 4, 242, 0xFFFFFF, "M: Map");
	mlx_string_put(s_m->mlx, s_m->win, 4, 262, 0xFFFFFF, "ESC: Exit");
	mlx_string_put(s_m->mlx, s_m->win, 4, 282, 0xFFFFFF, "SPACE: Shoot");
}

void	ft_text(t_master *s_m)
{
	if (s_m->width < 1920)
		ft_text_mac(s_m);
}