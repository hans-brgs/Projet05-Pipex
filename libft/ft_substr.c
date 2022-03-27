/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:50:09 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/04 21:30:17 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_alloc;

	if (!s)
		return (NULL);
	while (*s && start)
	{
		s++;
		start--;
	}
	len_alloc = ft_strlen(s);
	if (len_alloc > len)
		len_alloc = len;
	sub_str = malloc((len_alloc + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s, len_alloc + 1);
	return (sub_str);
}
