/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:52:55 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/23 10:38:01 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_check_resized(int base)
{
	if (base <= 1)
		return (1);
	else
		return (base);
}

int	ft_check_x_y(int x, char c)
{
	if (x < 1)
		return (1);
	if (c == 'y' && x >= HEIGHT)
		return (HEIGHT);
	if (c == 'x' && x >= WIDTH)
		return (WIDTH);
	return (x);
}

void	ft_set_cam(t_master *s_m, t_dir dir)
{
	s_m->player.dirX = dir.dirX;
	s_m->player.dirY = dir.dirY;
	s_m->player.planeX = dir.planeX;
	s_m->player.planeY = dir.planeY;
}

void	ft_set_dir(t_master *s_m, char c, char *str)
{
	if (c == 'N')
		ft_set_cam(s_m, (t_dir){0, -1, 1, 0});
	if (c == 'S')
		ft_set_cam(s_m, (t_dir){0, 1, -1, 0});
	if (c == 'E')
		ft_set_cam(s_m, (t_dir){1, 0, 0, 1});
	if (c == 'W')
		ft_set_cam(s_m, (t_dir){-1, 0, 0, -1});
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		str[0] = 'P';
}
