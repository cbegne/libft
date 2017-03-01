/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:34:38 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/28 14:55:33 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **t1, char **t2)
{
	char	**tab;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_tablen(t1);
	len2 = ft_tablen(t2);
	tab = (char**)ft_memalloc(sizeof(char*) * (len1 + len2 + 1));
	if (tab)
	{
		i = 0;
		while (*t1)
		{
			tab[i++] = ft_strdup(*t1);
			t1++;
		}
		while (*t2)
		{
			tab[i++] = ft_strdup(*t2);
			t2++;
		}
	}
	return (tab);
}
