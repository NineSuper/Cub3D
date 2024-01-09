/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:59:35 by tde-los-          #+#    #+#             */
/*   Updated: 2023/12/01 10:40:59 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Minimap : Afficher les murs/portes
* ft_map : aggrandir la map
? Afficher le joueur en temps direct 
*/

int	color_case(int c)
{
	if (c == 1)
		return (create_trgb(0, 107, 107, 107));
	if (c == 2)
		return (create_trgb(0, 0, 255, 0));
	if (c == 3)
		return (create_trgb(0, 255, 255, 255));
	if (c == 4)
		return (create_trgb(0, 0, 162, 255));
	if (c == 5)
		return (create_trgb(0, 51, 0, 0));
	return (0);
}

void	ft_draw_square(t_master *s_m, int x, int y, int c)
{
	int	i;
	int	j;
	int	w;
	int	h;

	if (s_m->minimap)
		return ;
	else
	{
		i = 7;
		while (++i <= 16)
		{
			j = 7;
			h = i + y * 8;
			while (++j <= 16)
			{
				w = j + x * 8;
				img_pix_put(&s_m->img, w, h, color_case(c));
			}
		}
	}
}

void	ft_minimap(t_master *s_m, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				ft_draw_square(s_m, x, y, 1);
			else if (map[y][x] == 'D')
				ft_draw_square(s_m, x, y, 3);
			else if (map[y][x] == 'B')
				ft_draw_square(s_m, x, y, 4);
			ft_draw_square(s_m, (int)(s_m->player.posx), \
				(int)(s_m->player.posy), 2);
		}
	}
}
