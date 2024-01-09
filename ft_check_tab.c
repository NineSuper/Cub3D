/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:04:26 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/22 13:15:07 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_error(t_master *s_m)
{
	free_tab(s_m->map.map);
	ft_error_map(MAP_NO, s_m);
}

void	check_one_map(t_master *s_m, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			str[i] = '1';
		if (str[i] != '1')
			ft_free_error(s_m);
	}
}

int	ft_char_map(t_master *s_m, char *str)
{
	int	i;

	i = -1;
	if (s_m->map.player > 1)
	{
		ft_printf("\033[1;43mIl y'a trop de joueurs\033[00m\n");
		return (1);
	}
	while (str[++i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			ft_set_dir(s_m, str[i], str + i);
			s_m->map.player++;
			break ;
		}
		else if (str[i] != '1' && str[i] != '0' && \
			str[i] != 'D' && str[i] != ' ' && str[i] != 'B')
			return (1);
	}
	ft_printf("\033[1;33m%s\033[0m\n", str);
	return (0);
}

/*
? check autour du '0' en carré 8 si le char n'est pas un espace
111
101
111
*/

void	ft_check_tab(t_master *s_m, t_map *s_map, char **map)
{
	int	i;
	int	len;

	i = -1;
	while (map[++i])
		if (!ft_strncmp("1111", map[i], 4))
			break ;
	if (!map[i])
		ft_free_error(s_m);
	s_m->map.player = 0;
	s_map->len = i;
	check_one_map(s_m, map[i]);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			ft_free_error(s_m);
		if (ft_char_map(s_m, map[i]))
			ft_free_error(s_m);
		i++;
	}
	if (!s_m->map.player)
		ft_free_error(s_m);
	check_one_map(s_m, map[i - 1]);
}
