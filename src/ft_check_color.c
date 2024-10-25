/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:24:25 by tde-los-          #+#    #+#             */
/*   Updated: 2023/12/01 10:39:17 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_rgb(char *str)
{
	int	i;
	int	color;

	i = 0;
	while ((str[i] == '\t' || str[i] == ' ') && str[i])
		i++;
	if (!str[i])
		return (-1);
	color = ft_atoi(str);
	if (color > 255)
		return (-1);
	return (color);
}

int	color_arg(char *str, char c)
{
	char	**tab;
	int		i;
	int		color;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	tab = ft_split(str + i, ',');
	i = -1;
	ft_printf("\033[1;28m%c: ", c);
	while (tab[++i])
	{
		color = get_rgb(tab[i]);
		if (color == -1)
		{
			ft_printf("\033[1;44m%s: [%d]\033[00m\n", ERROR_C, color);
			free_tab(tab);
			return (-1);
		}
	}
	i = create_trgb(0, get_rgb(tab[0]), get_rgb(tab[1]), get_rgb(tab[2]));
	ft_printf("%d,%d,%d", get_rgb(tab[0]), get_rgb(tab[1]), get_rgb(tab[2]));
	ft_printf("\033[0;00m\n");
	free_tab(tab);
	return (i);
}

int	check_arg_c(t_master *s_m, char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i++])
		if (str[i] == ',')
			j++;
	if (j != 2)
		return (-1);
	if (c == 'F')
		s_m->map.c_f = color_arg(str + 1, 'F');
	if (c == 'C')
		s_m->map.c_c = color_arg(str + 1, 'C');
	if (s_m->map.c_f == -1 || s_m->map.c_c == -1)
		return (0);
	return (1);
}

int	ft_check_color(t_master *s_m, char **tab, int i)
{
	int	j;
	int	k;

	j = 0;
	while (tab[++i])
	{
		k = 0;
		while (tab[i][k] == '\t' || tab[i][k] == ' ')
			k++;
		if (!ft_strncmp("F", tab[i] + k, 1))
			j += check_arg_c(s_m, tab[i] + k, 'F');
		if (!ft_strncmp("C", tab[i] + k, 1))
			j += check_arg_c(s_m, tab[i] + k, 'C');
	}
	if (j != 2)
		return (1);
	return (0);
}
