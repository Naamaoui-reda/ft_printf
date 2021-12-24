/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:53:23 by rnaamaou          #+#    #+#             */
/*   Updated: 2021/12/21 13:13:42 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putnbr_base_long(unsigned long nbr, char *base);
int		ft_putstr_fd(char*s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);

#endif
