/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:33:37 by rnaamaou          #+#    #+#             */
/*   Updated: 2021/12/21 16:22:52 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	ft_hex_len_long(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	unsigned int	nb;

	nb = n;
	if (nb / 16 != 0)
		ft_putnbr_base(nb / 16, base);
	write (1, &base[nb % 16], 1);
	return (ft_hex_len(n));
}

int	ft_putnbr_base_long(unsigned long nbr, char *base)
{
	unsigned long	nb;

	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base_long (nb / 16, base);
	write (1, &base[nb % 16], 1);
	return (ft_hex_len_long(nbr));
}
