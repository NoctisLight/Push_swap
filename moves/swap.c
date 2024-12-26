/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:58 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/26 17:50:12 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int list_len(stack_a *first_a)
{
    stack_a *tmp1;
    int i;

    if(!first_a)
        return (0);
    tmp1 = first_a;
    i = 0;
    while(tmp1)
    {
        i++;
        tmp1 = tmp1->next;
    }
    return (i);
}

stack_a *sa(stack_a *head_a, stack_a *first_a)
{
    stack_a *tmp1;
    int len;
    int valswap;
    int i = 0;

    tmp1 = head_a;
    len = list_len(first_a);
    if(len < 2)
        return head_a;
    while(len-2 > i)
    {
        first_a = first_a->next;
        i++;
    }
    valswap = first_a -> val; // keep the head-1 val temporarily
    ft_printf("Valswap Before : %d\n", valswap);
    ft_printf("Head Before : %d\n", head_a -> val);
    first_a -> val = head_a -> val;
    head_a -> val = valswap;
    ft_printf("Valswap After : %d\n", first_a -> val);
    ft_printf("Head after : %d\n", head_a -> val);
    return(head_a);
}

stack_a *sb(stack_a *head_b, stack_a *first_b)
{
    int len;
    int valswap;
    int i = 0;

    len = list_len(first_b);
    if(len < 2)
        return head_b;
    while(len-2 > i)
    {
        first_b = first_b->next;
        i++;
    }
    valswap = first_b -> val; // keep the head-1 val temporarily
    ft_printf("Valswap Before : %d\n", valswap);
    ft_printf("Head Before : %d\n", head_b -> val);
    first_b -> val = head_b -> val;
    head_b -> val = valswap;
    ft_printf("Valswap After : %d\n", first_b -> val);
    ft_printf("Head after : %d\n", head_b -> val);
    return(head_b);
}
