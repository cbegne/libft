/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:31:07 by cbegne            #+#    #+#             */
/*   Updated: 2017/02/21 10:25:59 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_no_arg(const char **format, char **s, int len_s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *s;
	while (**format && **format != '%')
	{
		i++;
		(*format)++;
	}
	*s = ft_strnnjoin(*s, *format - i, len_s, i);
	free(tmp);
	return (i);
}

static int	printf_arg(const char **format, va_list ap, char **s, int len_s)
{
	t_print param;
	char	*out;
	char	*tmp;
	int		len_out;

	parse(format, ap, &param);
	out = convert_and_apply(ap, &param);
	len_out = param.count;
	if (param.count != -1)
	{
		tmp = *s;
		*s = ft_strnnjoin(*s, out, len_s, len_out);
		free(tmp);
		free(out);
	}
	return (len_out);
}

static void	var_zero(int *i, int *count, int *nb)
{
	*i = 0;
	*count = 0;
	*nb = 0;
}

static int	start_printf(va_list ap, const char **format, char *s, int fd)
{
	int		count;
	int		i;
	int		nb;

	var_zero(&i, &count, &nb);
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			if ((count = printf_arg(format, ap, &s, nb)) != -1)
				nb = nb + count;
			else
				break ;
		}
		else
		{
			i = printf_no_arg(format, &s, nb);
			nb = nb + i;
		}
	}
	count != -1 ? write(fd, s, nb) : write(fd, s, nb - i);
	free(s);
	return (count == -1 ? -1 : nb);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	va_list ap;
	int		nb;
	char	*s;

	va_start(ap, format);
	s = ft_strdup("");
	nb = start_printf(ap, &format, s, fd);
	va_end(ap);
	return (nb);
}
