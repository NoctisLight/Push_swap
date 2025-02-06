/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:53:43 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/06 16:37:03 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(stack_a **head_a, stack_a **first_a)
{
    stack_a *save;

    save = (*first_a);
    if((*first_a)->next)
    {
        while((*first_a)->next->next) // Until last-1
        {
            (*first_a) = (*first_a)->next;
        }
        (*first_a) -> next = NULL; // set the head-1 to null
        save -> prev = (*head_a); //
        (*head_a) -> next = save;
        save = (*head_a);
        (*head_a) = (*first_a); // ok
        (*first_a) = save;
    }
    return ;
        
}

void rrb(stack_b **head_b, stack_b **first_b)
{
    stack_b *save;

    save = (*first_b);
    if((*first_b)->next)
    {
        while((*first_b)->next->next) // Until last-1
        {
            (*first_b) = (*first_b)->next;
        }
        (*first_b) -> next = NULL; // set the head-1 to null
        save -> prev = (*head_b); // 
        (*head_b) -> next = save;
        save = (*head_b);
        (*head_b) = (*first_b); // ok
        (*first_b) = save;
    }
    return ;
}

void rrr(stack_a **head_a, stack_a **first_a, stack_b **head_b, stack_b **first_b)
{
    rra(head_a, first_a);
    rrb(head_b, first_b);
}