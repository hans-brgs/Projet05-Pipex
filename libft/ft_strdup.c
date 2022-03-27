/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:04:32 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:07:22 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	size_t	len;

	len = ft_strlen(s) + 1;
	dup_str = malloc(len * sizeof(char));
	if (!dup_str)
		return (NULL);
	ft_strlcpy(dup_str, s, len);
	return (dup_str);
}
