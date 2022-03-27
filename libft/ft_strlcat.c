/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:46:10 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:07:14 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		j;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	while (len_dest + j + 1 < size && src[j])
	{
		dst[len_dest + j] = src[j];
		j++;
	}
	if (len_dest > size)
		return (len_src + size);
	dst[len_dest + j] = '\0';
	return (len_dest + len_src);
}
