/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:53:59 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/15 10:27:23 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_neg(int n)
{
	if (n <= -10)
	{
		ft_putnbr_neg(n / 10);
		ft_putchar(-(n % 10) + '0');
	}
	else if (n >= -9)
		ft_putchar(-n + '0');
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_neg(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}
