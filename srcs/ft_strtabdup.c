/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:31:09 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/17 15:51:32 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **env, int size)
{
	int		i;
	char	**tab;

	tab = (char**)ft_memalloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	return (tab);
}
