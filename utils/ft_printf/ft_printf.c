/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:06:48 by fben-ham          #+#    #+#             */
/*   Updated: 2024/11/23 15:40:43 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_u(unsigned int n, int *len)
{
	char	c;

	if (n == 2147483648)
	{
		*len += write(1, "2147483648", 10);
		return ;
	}
	if (n > 9)
		ft_putnbr_u(n / 10, len);
	c = (n % 10) + '0';
	*len += write(1, &c, 1);
}

static void	ft_check_p(int *len, va_list args)
{
	unsigned long int	arg;

	arg = va_arg(args, unsigned long int);
	if (!arg)
		*len += write(1, "(nil)", 5);
	else
	{
		*len += write(1, "0x", 2);
		ft_putnbr_base2(arg, "0123456789abcdef", len);
	}
}

static void	ft_checker(const char *s, int *len, va_list args)
{
	char	c;

	if (*s == 'c')
	{
		c = va_arg(args, int);
		*len += write(1, &c, 1);
	}
	if (*s == 's')
		ft_putstr(va_arg(args, char *), len);
	if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), len);
	if (*s == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", len);
	if (*s == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", len);
	if (*s == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	if (*s == 'p')
		ft_check_p(len, args);
}

static void	shorter(int *len, va_list args, const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				*len += write(1, "%", 1);
			else
				ft_checker(&format[i], len, args);
		}
		else
			*len += write(1, &format[i], 1);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	shorter(&len, args, format);
	va_end(args);
	return (len);
}
