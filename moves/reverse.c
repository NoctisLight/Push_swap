/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:53:43 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/28 19:44:51 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(stack_a **head_a, stack_a **first_a)
{
    int tmp;
    stack_a *tmp_first;
    stack_a *new_node;

    new_node = malloc(sizeof(stack_a));
    if(list_len_a(first_a) > 1)
    {
        tmp = (*first_a) -> val;
        tmp_first = (*first_a) -> next;
        free(first_a);
        first_a = tmp_first;

        
    }
    
}