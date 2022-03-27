/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:39:00 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/04 21:53:33 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_element(char const *s, char c)
{
	size_t	count;
	size_t	state;

	state = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			count++;
		}	
		s++;
	}
	return (count);
}

static size_t	ft_element_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_free_array(char **array, size_t n)
{
	while (n--)
		free(array[n]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	len_split;
	char	**array;
	int		nb_delim;	
	int		n;

	if (!s)
		return (NULL);
	n = -1;
	nb_delim = ft_count_element(s, c);
	array = malloc((nb_delim + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (n++ < nb_delim - 1)
	{
		while (*s == c)
			s++;
		len_split = ft_element_length(s, c);
		array[n] = ft_calloc(len_split + 1, sizeof(char));
		if (!array)
			return (ft_free_array(array, n));
		ft_strlcpy(array[n], s, len_split + 1);
		s = s + len_split;
	}
	array[nb_delim] = NULL;
	return (array);
}
