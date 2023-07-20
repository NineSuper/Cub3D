/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:56:49 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/20 22:25:01 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    ft_exit_menu(t_master *s_m)
{
    mlx_destroy_image(s_m->mlx, s_m->menu.menu_d);
    mlx_destroy_image(s_m->mlx, s_m->menu.menu_p);
    mlx_destroy_image(s_m->mlx, s_m->menu.menu_o);
    mlx_destroy_image(s_m->mlx, s_m->menu.menu_q);
    mlx_destroy_window(s_m->mlx, s_m->win);
    mlx_destroy_display(s_m->mlx);
    mlx_loop_end(s_m->mlx);
    free(s_m->mlx);
    free(s_m);
    exit (0);
}