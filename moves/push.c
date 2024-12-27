/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:44:04 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/27 13:58:14 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(stack_a **head_a, stack_b **head_b, stack_b *first_b)
{
    stack_a *new_node;
    if(list_len_b(first_b))
    {
        new_node = malloc(sizeof(stack_a));
        new_node -> val = (*head_b) -> val;
        new_node -> next = NULL;
        (*head_a) -> next = new_node;
        *head_a = (*head_a) -> next;
    }
    return ;
}

void pb(stack_a **head_a, stack_b **head_b, stack_a *first_a)
{
    stack_b *new_node;
    if(list_len_a(first_a))
    {
        new_node = malloc(sizeof(stack_b));
        new_node -> val = (*head_a) -> val;
        new_node -> next = NULL;
        (*head_b) -> next = new_node;
        *head_b = (*head_b) -> next;
    }
    return ;
}

