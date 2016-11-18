/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:27:22 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/15 11:41:20 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_fd_neg(int n, int fd)
{
	if (n <= -10)
	{
		ft_putnbr_fd_neg(n / 10, fd);
		ft_putchar_fd(-(n % 10) + '0', fd);
	}
	else if (n >= -9)
		ft_putchar_fd(-n + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_neg(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n <= 9)
		ft_putchar_fd(n + '0', fd);
}
