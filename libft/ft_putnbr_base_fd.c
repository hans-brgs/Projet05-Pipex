/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:48:19 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/18 10:26:48 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_base(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_putnbr_base_fd(unsigned long int nbr, char *base, int fd)
{
	unsigned long int	nbr_bis;
	size_t				size_base;
	static int			size;

	size = 0;
	nbr_bis = 0;
	size_base = check_base(base);
	if (!size_base)
		return (size);
	nbr_bis = nbr;
	if (nbr_bis > size_base - 1)
	{
		ft_putnbr_base_fd(nbr_bis / size_base, base, fd);
		nbr_bis %= size_base;
	}
	if (nbr_bis < size_base)
		size += ft_putchar_fd(base[nbr_bis], fd);
	return (size);
}
