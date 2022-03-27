/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:52:48 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 19:43:33 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	static int		size;
	unsigned int	n_bis;

	size = 0;
	n_bis = n;
	if (n_bis > 9)
	{
		ft_putnbr_unsigned_fd(n_bis / 10, fd);
		n_bis %= 10;
	}
	if (n_bis < 10)
		size += ft_putchar_fd(n_bis + '0', fd);
	return (size);
}
