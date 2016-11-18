/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:57:01 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/12 16:46:50 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_neg(char *tab, int len, int n)
{
	while (n)
	{
		tab[len] = -(n % 10) + '0';
		n = n / 10;
		len--;
	}
	tab[0] = '-';
	return (tab);
}

static char	*itoa_pos(char *tab, int len, int n)
{
	while (n)
	{
		tab[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (tab);
}

char		*ft_itoa(int n)
{
	char	*tab;
	size_t	len;
	int		i;

	i = n;
	len = 0;
	while (i)
	{
		i = i / 10;
		len++;
	}
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	if (!(tab = ft_strnew(len)))
		return (NULL);
	len--;
	if (n < 0)
		tab = itoa_neg(tab, len, n);
	else if (n == 0)
		tab[0] = '0';
	else
		tab = itoa_pos(tab, len, n);
	return (tab);
}
