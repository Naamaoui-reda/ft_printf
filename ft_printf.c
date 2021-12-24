/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:03:55 by rnaamaou          #+#    #+#             */
/*   Updated: 2021/12/22 13:29:30 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_charexist(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	print_by_type(char type, va_list arg)
{
	char	*hex_lo;
	char	*hex_up;

	hex_lo = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (type == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(arg, unsigned int), 1));
	else if (type == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (type == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (type == 'x')
		return (ft_putnbr_base(va_arg(arg, int), hex_lo));
	else if (type == 'X')
		return (ft_putnbr_base(va_arg(arg, int), hex_up));
	else if (type == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_base_long(va_arg(arg, unsigned long), hex_lo) + 2);
	}
	else if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static void	test_sp(const char *s, int *i)
{
	while (s[(*i) + 1] == ' ')
		(*i)++;
	(*i)++;
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start (args, s);
	while (s[i])
	{
		while (s[i])
		{
			if (s[i] == '%' && ft_charexist(s[i + 1], "xXdscipu%"))
				break ;
			else if (s[i] == '%')
				test_sp(s, &i);
			len += ft_putchar_fd(s[i++], 1);
		}
		if (s[i])
		{
			len += print_by_type(s[i +1], args);
			i += 2;
		}
	}
	va_end(args);
	return (len);
}
