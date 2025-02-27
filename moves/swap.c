/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:58 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/27 15:33:38 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

///////// NEED TO IMRPOVE THE MAIN FUNCTIONS AND DELETE BOTH LIST_LEN_FCT
int list_len_a(stack_a *first_a) // stack_a used
{
    int i;
    stack_a *tmp1;

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

int list_len_b(stack_b *first_b) // stack_b used
{
    int i;
    stack_b *tmp1;

    if(!first_b)
        return (0);
    tmp1 = first_b;
    i = 0;
    while(tmp1)
    {
        i++;
        tmp1 = tmp1->next;
    }
    return (i);
}

void sa(stack_a **head_a)
{
    int valswap;

    if(!(*head_a)->prev)
        return ;
    
    valswap = (*head_a)-> val; // keep the head val temporarily
    (*head_a) -> val = (*head_a) -> prev -> val;
    (*head_a) -> prev -> val = valswap;
}

void sb(stack_b **head_b)
{
    int valswap;

    if(!(*head_b)->prev)
        return ;
    
    valswap = (*head_b)-> val; // keep the head val temporarily
    (*head_b) -> val = (*head_b) -> prev -> val;
    (*head_b) -> prev -> val = valswap;
}

void ss(stack_a **head_a, stack_b **head_b) // execute both functions
{
    sa(head_a);
    sb(head_b);
}
