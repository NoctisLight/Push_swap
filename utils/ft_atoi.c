/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:50:45 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/19 16:38:59 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_atoi(const char *string)
{
    int nb = 0;
    int sign = 1; 
    
    while (*string >= 9 && *string <= 13)
        string++;
    if (*string == '-' || *string == '+') {
        if (*string == '-')
            sign = -1;
        string++;
    }
    while (*string >= '0' && *string <= '9') {
        nb = nb * 10 + (*string - '0');
        string++;
    }
    return nb * sign;
}