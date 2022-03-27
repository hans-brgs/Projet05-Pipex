/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:38:29 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/01 17:08:19 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_length(unsigned int tmp)
{
	size_t	len_nbr;

	len_nbr = 0;
	if (tmp == 0)
		return (len_nbr + 1);
	while (tmp > 0)
	{
		tmp /= 10;
		len_nbr++;
	}
	return (len_nbr);
}

char	*ft_itoa(int nbr)
{
	unsigned int	tmp;
	size_t			len_nbr;
	char			*str;
	int				isneg;

	isneg = 0;
	if (nbr < 0)
	{
		tmp = -nbr;
		isneg = 1;
	}
	else
		tmp = nbr;
	len_nbr = isneg + ft_number_length(tmp);
	str = ft_calloc(len_nbr + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len_nbr--)
	{
		str[len_nbr] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (nbr < 0)
		str[0] = '-';
	return (str);
}
