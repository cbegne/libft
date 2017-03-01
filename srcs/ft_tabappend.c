/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:12:19 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/28 16:05:34 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabappend(char **tab, char *str)
{
	char	**new_tab;
	int		len;
	int		i;

	i = 0;
	len = ft_tablen(tab);
	new_tab = (char**)ft_memalloc(sizeof(char*) * (len + 2));
	while (i < len)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(str);
	return (new_tab);
}
