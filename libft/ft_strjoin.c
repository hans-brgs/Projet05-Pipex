/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:33:06 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:07:17 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	len_str_join;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	n = 0;
	len_str_join = ft_strlen(s1) + ft_strlen(s2);
	str_join = ft_calloc(len_str_join + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	while (*s1)
	{
		str_join[n] = *s1;
		s1++;
		n++;
	}
	while (*s2)
	{
		str_join[n] = *s2;
		s2++;
		n++;
	}
	return (str_join);
}
