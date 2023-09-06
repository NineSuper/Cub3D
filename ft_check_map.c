/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:42:49 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/06 09:17:31 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Check maps.cub
* Commencer par check_textures
* Check les colors puis les convertir en hexadecimal
* Check toute la map 
* tout doit etre entouree de 1
* Char = '1' '0' 'B' 'P' ('N' | 'S' | 'W' | 'E')
* UNIQUEMENT une lettre parmis celles-ci : N | S | W | E
* La sortie : B
* La porte : P
* tout free une fois fini
*/

void	ft_check_arg(t_map *s_map, t_master *s_m, char **tab)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	ft_printf("\033[1;47m\t %s \033[00m\n", s_map->level);
	while (tab[++i])
		j += ft_msg(tab[i], s_m);
	ft_printf("--------------------------------\n");
	j += check_texture(s_map->no, s_map->ea, s_map->so, s_map->we);
	if (j != 4 || ft_check_color(s_m, s_m->map.map, -1))
	{	
		free_tab(s_map->map);
		ft_error_map(ERROR_T, s_m);
	}
	ft_printf("--------------------------------\n");
}

void	ft_read_map(int fd, t_map *s_map, t_master *s_m)
{
	char	*temp_map;
	char	buff[1];
	int		size;

	size = 1;
	if (s_map->map)
		free_tab(s_map->map);
	if (fd < 0 || read(fd, 0, 0) < 0)
		ft_error_map(READ_ERR, s_m);
	temp_map = ft_calloc(1, sizeof(char));
	while (size != 0)
	{
		size = read(fd, buff, 1);
		temp_map = gnl_ft_strjoin(temp_map, buff);
	}
	close (fd);
	s_map->map = ft_split(temp_map, '\n');
	if (temp_map)
		free(temp_map);
	ft_check_arg(s_map, s_m, s_map->map);
}

void	ft_check_map(t_master *s_m, char *map)
{
	s_m->map.level = map;
	s_m->map.fd = open(s_m->map.level, O_RDONLY);
	ft_read_map(s_m->map.fd, &s_m->map, s_m);
	ft_check_tab(s_m, &s_m->map, s_m->map.map);
	ft_menu(s_m);
}
