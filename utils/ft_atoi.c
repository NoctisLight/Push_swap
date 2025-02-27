/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:50:45 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/27 15:12:39 by fben-ham         ###   ########.fr       */
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
    else if(num < (*data)->min)
        (*data)->min = num;
}

int ft_atoi(stack_a *first, stack_a **head, const char *string, t_data **data)
{
    int nb = 0;
    int sign = 1;
    stack_a *tmp;
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
        if((*data) -> nb_nodes == 0) // there is probably a better way
        {
            if (check_doubles(first, nb))
            {
                (*head) -> val = nb * sign;
                (*head) -> next = NULL;
                (*head) -> prev = NULL;
                highest_number(nb * sign, data);
                (*data) -> nb_nodes +=1;
                return 1;
            }
        }
        if (check_doubles(first, nb))
        {
            tmp = malloc(sizeof(stack_a));
            tmp -> val = nb * sign;
            tmp -> next = NULL;
            tmp -> prev = (*head);
            (*head) -> next = tmp;
            (*head) = (*head)->next;
            highest_number(nb * sign, data);
            return 1;
        }
    }
    return 0;
}


