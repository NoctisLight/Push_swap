/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:44:04 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/27 17:18:09 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(stack_a **head_a, stack_b **head_b, stack_b *first_b)
{
    stack_a *new_node;
    int i;
    
    if(list_len_b(first_b))
    {
        i = list_len_b(first_b) - 1;
        new_node = malloc(sizeof(stack_a));
        new_node -> val = (*head_b) -> val;
        new_node -> next = NULL;
        new_node -> prev = (*head_a); // link the current last b node before the push
        while(i) // will get the lastnode-1 temporarly before deleting it
        {
            first_b = first_b -> next;
            i--;
        }
        free((*head_b));
        first_b -> next = NULL;
        (*head_b) = first_b;
        (*head_a) -> next = new_node;
        *head_a = (*head_a) -> next;
    }
    return ;
}

void pb(stack_a **head_a, stack_b **head_b, stack_a *first_a)
{
    stack_b *new_node;
    int i;

    if(list_len_a(first_a))
    {
        i = (list_len_a(first_a) - 2);
        new_node = malloc(sizeof(stack_b));
        new_node -> val = (*head_a) -> val;
        new_node -> next = NULL;
        new_node -> prev = (*head_b); // link the current last b node before the push
        while(i) // will get the lastnode-1 temporarly before deleting it
        {
            first_a = first_a -> next;
            i--;
        }
        free((*head_a));
        first_a -> next = NULL;
        (*head_a) = first_a;
        (*head_b) -> next = new_node;
        *head_b = (*head_b) -> next;
    }
    return ;
}

