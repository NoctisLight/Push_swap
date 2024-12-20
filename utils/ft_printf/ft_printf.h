/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:37:18 by fben-ham          #+#    #+#             */
/*   Updated: 2024/11/23 15:25:15 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr_base2(unsigned long int nb, char *base, int *len);
void	ft_putnbr_base(unsigned int nb, char *base, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
int		ft_printf(const char *format, ...);

#endif