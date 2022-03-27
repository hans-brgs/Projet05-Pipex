/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:28:00 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:07:11 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len_src);
	else
	{
		while (*src && i < size - 1)
		{
			dst[i] = *src;
			src++;
			i++;
		}
		dst[i] = '\0';
		return (len_src);
	}
}
