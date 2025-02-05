/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:50:45 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/05 06:45:58 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int check_doubles(stack_a *first, int nb)
{
    stack_a *tmp1;

    if(!first)
        return 0;
    tmp1 = first;
    while(tmp1)
    {
        if (tmp1->val == nb)
            return (0);
        tmp1 = tmp1->next;
    }
    return (1);
}

void highest_number(int num, t_data **data)
{
    if (num > (*data)->max)
        (*data)->max = num;
}

stack_a *ft_atoi(stack_a *first, stack_a *head, const char *string, t_data **data)
{
    int nb = 0;
    int sign = 1;
    stack_a *tmp;
    //stack_a *tmp_prev;

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
        if (check_doubles(first, nb))
        {
            tmp = malloc(sizeof(stack_a));
            tmp -> val = nb * sign;
            tmp -> next = NULL;
            tmp -> prev = head;
            head -> next = tmp;
            head = head->next;
            highest_number(nb, data);
            return (head);
        }
    }
    return (0);
}


