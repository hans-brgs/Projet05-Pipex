/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:06:53 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:06:58 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	while (*s)
	{
		s++;
	}
	while (*s != (char)c)
	{
		if (len_s == 0)
			return (NULL);
		s--;
		len_s--;
	}
	return ((char *)s);
}
