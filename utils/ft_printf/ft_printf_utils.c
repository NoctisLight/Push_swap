/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:06:16 by fben-ham          #+#    #+#             */
/*   Updated: 2024/11/22 17:53:48 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base2(unsigned long int nb, char *base, int *len)
{
	if (nb > 15)
		ft_putnbr_base2(nb >> 4, base, len);
	*len += write(1, &base[nb % 16], 1);
}

void	ft_putnbr_base(unsigned int nb, char *base, int *len)
{
	if (nb > 15)
		ft_putnbr_base(nb >> 4, base, len);
	*len += write(1, &base[nb % 16], 1);
}

void	ft_putstr(char *str, int *len)
{
	if (str == NULL)
		*len += write(1, "(null)", 6);
	else
		while (*str)
			*len += write(1, str++, 1);
}

void	ft_putnbr(int n, int *len)
{
	char	c;

	if (n == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	c = (n % 10) + '0';
	*len += write(1, &c, 1);
}
