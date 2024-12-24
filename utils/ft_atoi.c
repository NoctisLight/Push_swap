/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:50:45 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/24 14:25:52 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack_a *ft_atoi(stack_a *head, const char *string)
{
    int nb = 0;
    int sign = 1;
    stack_a *tmp;

    while (*string >= 9 && *string <= 13)
        string++;
    if (*string == '-' || *string == '+') {
        if (*string == '-')
            sign = -1;
        string++;
    }
    if (*string >= '0' && *string <= '9') {
        while (*string >= '0' && *string <= '9') {
            nb = nb * 10 + (*string - '0');
            string++;
        }
        tmp = malloc(sizeof(stack_a));
        tmp -> val = nb * sign;
        tmp -> next = NULL;
        head -> next = tmp;
    }
    else
    {    ft_printf("Error\n");
        return (0);
    }
    return (head);
}