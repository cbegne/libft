/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:12:09 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/10 17:16:33 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	ft_memset(str, c, size);
	str[i] = '\0';
	return (str);
}
