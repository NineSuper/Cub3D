/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:56:49 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 22:42:27 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_map(t_map *s_map)
{
	free(s_map->no);
	free(s_map->ea);
	free(s_map->so);
	free(s_map->we);
}

void	ft_error_map(char *error, t_master *s_m)
{
	ft_printf("\033[1;41mMAP  %s %s\033[00m\n", s_m->map.level, error);
	free_map(&s_m->map);
	free(s_m->mlx);
	free(s_m);
	exit (0);
}

void	ft_destroy_img(void *mlx, char *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

int	ft_exit_menu(t_master *s_m)
{
	ft_destroy_img(s_m->mlx, s_m->menu.menu_d);
	ft_destroy_img(s_m->mlx, s_m->menu.menu_p);
	ft_destroy_img(s_m->mlx, s_m->menu.menu_o);
	ft_destroy_img(s_m->mlx, s_m->menu.menu_q);
	ft_destroy_img(s_m->mlx, s_m->player.cross.m_img);
	ft_destroy_img(s_m->mlx, s_m->cursor.m_img);
	ft_destroy_img(s_m->mlx, s_m->skyfloor.m_img);
	ft_destroy_img(s_m->mlx, s_m->we.m_img);
	ft_destroy_img(s_m->mlx, s_m->so.m_img);
	ft_destroy_img(s_m->mlx, s_m->no.m_img);
	ft_destroy_img(s_m->mlx, s_m->ea.m_img);
	ft_destroy_img(s_m->mlx, s_m->img.m_img);
	ft_destroy_img(s_m->mlx, s_m->door.m_img);
	ft_destroy_img(s_m->mlx, s_m->exit.m_img);
	if (s_m->win)
		mlx_destroy_window(s_m->mlx, s_m->win);
	mlx_destroy_display(s_m->mlx);
	mlx_loop_end(s_m->mlx);
	if (s_m->map.map)
		free_tab(s_m->map.map);
	free_map(&s_m->map);
	free(s_m->mlx);
	free(s_m);
	exit (0);
}
