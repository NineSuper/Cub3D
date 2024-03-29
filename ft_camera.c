/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:03:30 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 16:51:50 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

void	ft_cam(int key, t_player *player, double rotSpeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->dirx;
	oldplanex = player->planex;
	if (key == 97)
	{
		player->dirx = player->dirx * cos(-rotSpeed) - \
			player->diry * sin(-rotSpeed);
		player->diry = olddirx * sin(-rotSpeed) + player->diry * cos(-rotSpeed);
		player->planex = player->planex * cos(-rotSpeed) - \
			player->planey * sin(-rotSpeed);
		player->planey = oldplanex * sin(-rotSpeed) + \
			player->planey * cos(-rotSpeed);
	}
	if (key == 100)
	{
		player->dirx = player->dirx * cos(rotSpeed) - \
			player->diry * sin(rotSpeed);
		player->diry = olddirx * sin(rotSpeed) + player->diry * cos(rotSpeed);
		player->planex = player->planex * cos(rotSpeed) - \
			player->planey * sin(rotSpeed);
		player->planey = oldplanex * sin(rotSpeed) + \
			player->planey * cos(rotSpeed);
	}
}
