/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:41:26 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 23:23:58 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_ray(t_player *player, int x)
{
	if (!player->posx && !player->posy)
	{
		player->posx = player->x;
		player->posy = player->y;
	}
	player->camerax = (((double)x * 2) / (double)WIDTH) - 1;
	player->raydirx = player->dirx + (player->planex * player->camerax);
	player->raydiry = player->diry + (player->planey * player->camerax);
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
	player->deltadistx = (1 / player->raydirx) * \
		(1 - (2 * (1 / player->raydirx < 0)));
	player->deltadisty = (1 / player->raydiry) * \
		(1 - (2 * (1 / player->raydiry < 0)));
}

void	ft_step(t_player *player)
{
	if (player->raydirx < 0)
	{
		player->stepx = -1;
		player->sidedistx = (player->posx - player->mapx)
			* player->deltadistx;
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (player->mapx + 1.0 - player->posx)
			* player->deltadistx;
	}
	if (player->raydiry < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->posy - player->mapy)
			* player->deltadisty;
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (player->mapy + 1.0 - player->posy)
			* player->deltadisty;
	}
}

void	ft_dda(t_player *player, char **map)
{
	player->hit = 0;
	while (player->hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{
			player->sidedistx += player->deltadistx;
			player->mapx += player->stepx;
			player->side = 0;
		}
		else
		{
			player->sidedisty += player->deltadisty;
			player->mapy += player->stepy;
			player->side = 1;
		}
		if (map[player->mapy][player->mapx] == '1')
			player->hit = 1;
		if (map[player->mapy][player->mapx] == 'D')
			player->hit = 2;
		if (map[player->mapy][player->mapx] == 'B')
			player->hit = 3;
	}
}

double	ft_per_wall(t_player *player)
{
	if (player->side == 0)
		player->perpwalldist = player->sidedistx - player->deltadistx;
	else
		player->perpwalldist = player->sidedisty - player->deltadisty;
	return (player->perpwalldist);
}

void	ft_ray(t_master *s_m, t_player *player, char **map)
{
	int	x;
	int	drawstart;
	int	drawend;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_ray(player, x);
		ft_step(player);
		ft_dda(player, map);
		ft_per_wall(player);
		player->lineheight = (int)(HEIGHT / player->perpwalldist);
		drawstart = ((-1 * player->lineheight) / 2) + (HEIGHT / 2);
		if (drawstart < 0)
			drawstart = 0;
		drawend = (player->lineheight / 2) + (HEIGHT / 2);
		if (drawend >= HEIGHT)
			drawend = HEIGHT - 1;
		ft_wall_sheets(player, s_m);
		ft_texture(s_m, (t_draw){drawstart, drawend}, x, &s_m->player);
	}
}
