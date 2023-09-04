/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:52:55 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/04 11:47:54 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    ft_set_cam(t_master *s_m, int dirx, int diry, int posx)
{
    s_m->player.dirx = dirx;
    s_m->player.diry = diry;
    s_m->player.posX = posx;
    s_m->player.posY = 0.66;
}

void	ft_set_dir(t_master *s_m, char c, char *str)
{
	if (c == 'N')
        ft_set_cam(s_m, 0, -1, 0);
	if (c == 'S')
		ft_set_cam(s_m, 0, 1, 0);
	if (c == 'E')
		ft_set_cam(s_m, 1, 0, 0);
	if (c == 'W')
		ft_set_cam(s_m, -1, 0, 0);
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		str[0] = 'P';
}
