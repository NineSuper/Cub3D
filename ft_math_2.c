/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:45:33 by lumontgo          #+#    #+#             */
/*   Updated: 2024/01/09 18:56:21 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_wall_sheets(t_player *player, t_master *s_m)
{
	if (player->side == 0 && player->hit == 1)
	{
		if (player->raydirx > 0)
			player->target = s_m->ea;
		else
			player->target = s_m->we;
	}
	else if (player->side == 1 && player->hit == 1)
	{
		if (player->raydiry > 0)
			player->target = s_m->no;
		else
			player->target = s_m->so;
	}
	else if (player->hit == 2)
		player->target = s_m->door;
	else if (player->hit == 3)
		player->target = s_m->exit;
}

void	ft_texture(t_master *s_m, t_draw draw, int x, t_player *player)
{
	int	y;

	if (player->side == 0)
		player->wallx = player->posy + player->perpwalldist * player->raydiry;
	else
		player->wallx = player->posx + player->perpwalldist * player->raydirx;
	player->wallx -= floor(player->wallx);
	player->texx = (int)(player->wallx * (double)(player->target.w));
	if (player->side == 0 && player->raydirx > 0)
		player->texx = player->target.w - player->texx - 1;
	if (player->side == 1 && player->raydiry < 0)
		player->texx = player->target.w - player->texx - 1;
	player->step = 1.0 * player->target.h / player->lineheight;
	player->texpos = (draw.drawstart - HEIGHT / 2
			+ player->lineheight / 2) * player->step;
	y = draw.drawstart;
	while (y < draw.drawend)
	{
		player->texy = (int)player->texpos & (player->target.h - 1);
		player->texpos += player->step;
		put_pixel_img(s_m->img, x, y,
			get_pixel_img(player->target, player->texx, player->texy));
		y++;
	}
}
