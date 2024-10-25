/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:31:27 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/10 01:16:14 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_texture(char *NO, char *EA, char *SO, char *WE)
{
	if (!NO || !EA || !SO || WE)
		return (0);
	if (!ft_strncmp("ERROR", EA, 5))
		return (1);
	if (!ft_strncmp("ERROR", NO, 5))
		return (1);
	if (!ft_strncmp("ERROR", SO, 5))
		return (1);
	if (!ft_strncmp("ERROR", WE, 5))
		return (1);
	return (0);
}

char	*ft_rspace(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\t')
			str[i] = ' ';
	return (str);
}

char	*ft_split_text(char *str)
{
	char	**tab;
	char	*new;

	str = ft_rspace(str);
	str = ft_space(str);
	tab = ft_split(str, ' ');
	if (!tab[1])
	{
		free_tab(tab);
		return (ft_strdup("ERROR"));
	}
	new = malloc(sizeof(char) * ft_strlen(tab[1]) + 1);
	ft_strlcpy(new, tab[1], ft_strlen(tab[1]) + 1);
	free_tab(tab);
	return (new);
}
