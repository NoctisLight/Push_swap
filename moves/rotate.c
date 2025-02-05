/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:00:44 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/05 05:22:35 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(stack_a **head_a, stack_a **first_a)
{
    stack_a *save;

    save = (*first_a);

    if((*first_a)->next)
    {
        (*first_a) = (*first_a)->next;
        (*head_a) -> next = save;
        (*head_a) = (*head_a) -> next;
        (*head_a) -> next = NULL;
    }
    return ;
}

void rb(stack_b **head_b, stack_b **first_b)
{
    stack_b *save;

    save = (*first_b);

    if((*first_b)->next)
    {
        (*first_b) = (*first_b)->next;
        (*head_b) -> next = save;
        (*head_b) = (*head_b) -> next;
        (*head_b) -> next = NULL;
    }
    return ;
}

void rr(stack_a **head_a, stack_a **first_a, stack_b **head_b, stack_b **first_b)
{
    ra(head_a, first_a);
    rb(head_b, first_b);
}