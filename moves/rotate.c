/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:00:44 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/27 14:26:14 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(stack_a **head_a, stack_a *first_a)
{
    int tmp;
    int tmp2;

    tmp = 0;
    tmp2 = 0;
    if(list_len_a(first_a))
    {
        tmp = first_a -> val;
        first_a -> val = (*head_a) -> val;
        first_a = first_a -> next;
        while(first_a)
        {
            tmp2 = first_a -> val;
            first_a -> val = tmp;
            tmp = tmp2;
            first_a = first_a -> next;
        }   
    }
    return ;
}

void rb(stack_b **head_b, stack_b *first_b)
{
    int tmp;
    int tmp2;

    tmp = 0;
    tmp2 = 0;
    if(list_len_b(first_b))
    {
        tmp = first_b -> val;
        first_b -> val = (*head_b) -> val;
        first_b = first_b -> next;
        while(first_b)
        {
            tmp2 = first_b -> val;
            first_b -> val = tmp;
            tmp = tmp2;
            first_b = first_b -> next;
        }   
    }
    return ;
}

void rr(stack_a **head_a, stack_a *first_a, stack_b **head_b, stack_b *first_b)
{
    ra(head_a, first_a);
    rb(head_b, first_b);
}