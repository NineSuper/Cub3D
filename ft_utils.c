/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:38:51 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/06 07:16:44 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_printf("%s\n", tab[i]);
}

int	ft_msg(char *str, t_master *s_m)
{
	if (!ft_strncmp("NO", str, 2))
	{
		s_m->map.no = ft_split_text(str, s_m);
		ft_printf("%sNO: %s\033[00m\n", C_GREEN, s_m->map.no);
	}
	else if (!ft_strncmp("SO", str, 2))
	{
		s_m->map.so = ft_split_text(str, s_m);
		ft_printf("%sSO: %s\033[00m\n", C_GREEN, s_m->map.so);
	}
	else if (!ft_strncmp("WE", str, 2))
	{
		s_m->map.we = ft_split_text(str, s_m);
		ft_printf("%sWE: %s\033[00m\n", C_GREEN, s_m->map.we);
	}
	else if (!ft_strncmp("ea", str, 2))
	{
		s_m->map.ea = ft_split_text(str, s_m);
		ft_printf("%sEA: %s\033[00m\n", C_GREEN, s_m->map.ea);
	}
	else
		return (0);
	return (1);
}
