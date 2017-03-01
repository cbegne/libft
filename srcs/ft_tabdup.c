/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:57:41 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/28 14:11:23 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **env)
{
	int		i;
	char	**tab;
	int		len;

	len = ft_tablen(env);
	tab = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	i = 0;
	while (i < len)
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	return (tab);
}
