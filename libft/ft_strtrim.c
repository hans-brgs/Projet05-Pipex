/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:55:11 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:06:55 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_continuous_occ(char const *s1, char const *set)
{
	size_t	occ;

	occ = 0;
	while (s1[occ])
	{
		if (ft_strchr(set, s1[occ]) != NULL)
			occ++;
		else
			return (occ);
	}
	return (occ);
}

static size_t	ft_continuous_occ_rev(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	occ;

	s1_len = ft_strlen(s1);
	occ = 0;
	while (s1_len--)
	{
		if (ft_strchr(set, s1[s1_len]) != NULL)
			occ++;
		else
			return (occ);
	}
	return (occ);
}

static void	ft_cpytrim(char const *s1, char *str_trim, int keep)
{
	while (keep--)
	{
		*str_trim = *s1;
		s1++;
		str_trim++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		trim_start;
	size_t		trim_end;
	char		*str_trim;
	int			keep;

	if (!s1 || !set)
		return (NULL);
	trim_start = ft_continuous_occ(s1, set);
	trim_end = ft_continuous_occ_rev(s1, set);
	keep = ft_strlen(s1) - (trim_end + trim_start);
	if (keep < 0)
		return (ft_strdup(""));
	str_trim = ft_calloc(keep + 1, sizeof(char));
	if (!str_trim)
		return (NULL);
	while (trim_start--)
		s1++;
	ft_cpytrim(s1, str_trim, keep);
	return (str_trim);
}
