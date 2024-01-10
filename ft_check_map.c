/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:42:49 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/10 11:15:44 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_recheck(t_master *s_m, char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (!ft_strncmp("NO", ft_space(tab[i]), 2) && s_m->map.no)
			count++;
		if (!ft_strncmp("SO", ft_space(tab[i]), 2) && s_m->map.so)
			count++;
		if (!ft_strncmp("WE", ft_space(tab[i]), 2) && s_m->map.we)
			count++;
		if (!ft_strncmp("EA", ft_space(tab[i]), 2) && s_m->map.ea)
			count++;
		if (!ft_strncmp("ERROR", ft_space(tab[i]), 5))
			s_m->error = 1;
		i++;
	}
	if (count != 4)
		s_m->error = 1;
}

void	ft_check_arg(t_map *s_map, t_master *s_m, char **tab)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	ft_printf("\033[1;47m\t %s \033[00m\n", s_map->level);
	if (s_m->error == 1)
	{
		free_tab(s_map->map);
		ft_error_map(ERROR_T, s_m);
	}
	while (tab[++i])
		j += ft_msg(tab[i], s_m);
	ft_printf("--------------------------------\n");
	j += check_texture(s_map->no, s_map->ea, s_map->so, s_map->we);
	ft_recheck(s_m, tab);
	if (j != 4 || ft_check_color(s_m, s_m->map.map, -1) || s_m->error == 1)
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
		if (!size)
			break ;
		temp_map = gnl_ft_strjoin(temp_map, buff);
	}
	close (fd);
	s_map->map = ft_split(temp_map, '\n');
	if (temp_map)
		free(temp_map);
	ft_check_arg(s_map, s_m, s_map->map);
}

// void	ft_flood_fill(char **map, t_coords coords, t_master *s_m)
// {
// 	printf("%s %d %d\n", map[y], x, y);
// 	if (!map[y][x])
// 	{
// 		s_m->error = 1;
// 		return ;
// 	}
// 	if (map[y][x] == '1' || map[y][x] == 'X')
// 		return ;
// 	map[y][x] = 'X';
// 	 ft_flood_fill(map, x, y + 1, s_m);
// 	 ft_flood_fill(map, x, y - 1, s_m);
// 	 ft_flood_fill(map, x - 1, y, s_m);
// 	 ft_flood_fill(map, x + 1, y, s_m);
// 	(void)s_m;
// }

// void	ft_recursive(t_master *s_m)
// {
// 	t_coords	coords;
// 	char	**map;
// 	int		y;
// 	int		x;

// 	y = 0;
// 	map = s_m->map.map + s_m->map.len;
// 	while (map[y])
// 	{
// 		printf("%s\n", map[y]);
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == 'P')
// 			{
// 				coords.x = x;
// 				coords.y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	ft_flood_fill(map, coords, s_m);
// }

void	ft_check_map(t_master *s_m, char *map)
{
	s_m->map.level = map;
	s_m->map.fd = open(s_m->map.level, O_RDONLY);
	ft_read_map(s_m->map.fd, &s_m->map, s_m);
	ft_check_tab(s_m, &s_m->map, s_m->map.map);
	// ft_recursive(s_m);
	ft_menu(s_m);
}
