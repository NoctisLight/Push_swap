/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:53:43 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/28 19:52:32 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(stack_a **head_a, stack_a **first_a)
{
    int tmp;
    stack_a *tmp_first;
    stack_a *new_node;

    new_node = malloc(sizeof(stack_a));
    if(list_len_a((*first_a)) > 1)
    {
        // save our first val and delete the node
        tmp = (*first_a) -> val;
        tmp_first = (*first_a) -> next;
        free((*first_a));
        (*first_a) = tmp_first;

        // create a new node with the initial first val
        new_node -> val = tmp;
        new_node -> next = NULL;
        (*head_a) -> next = new_node;
        (*head_a) = (*head_a) -> next;
    }
}