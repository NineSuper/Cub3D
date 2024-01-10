/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:38:51 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/10 01:19:02 by tde-los-         ###   ########.fr       */
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

char	*ft_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

int	ft_msg(char *str, t_master *s_m)
{
	if (!ft_strncmp("NO", ft_space(str), 2) && !s_m->map.no)
	{
		s_m->map.no = ft_split_text(str);
		ft_printf("%sNO: %s\033[00m\n", C_GREEN, s_m->map.no);
	}
	else if (!ft_strncmp("SO", ft_space(str), 2) && !s_m->map.so)
	{
		s_m->map.so = ft_split_text(str);
		ft_printf("%sSO: %s\033[00m\n", C_GREEN, s_m->map.so);
	}
	else if (!ft_strncmp("WE", ft_space(str), 2) && !s_m->map.we)
	{
		s_m->map.we = ft_split_text(str);
		ft_printf("%sWE: %s\033[00m\n", C_GREEN, s_m->map.we);
	}
	else if (!ft_strncmp("EA", ft_space(str), 2) && !s_m->map.ea)
	{
		s_m->map.ea = ft_split_text(str);
		ft_printf("%sEA: %s\033[00m\n", C_GREEN, s_m->map.ea);
	}
	else
		return (0);
	return (1);
}
