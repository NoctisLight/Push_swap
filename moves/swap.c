/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:58 by fben-ham          #+#    #+#             */
/*   Updated: 2025/02/06 16:24:48 by fben-ham         ###   ########.fr       */
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

void sa(stack_a **head_a, stack_a *first_a)
{
    int len;
    int valswap;
    int i = 0;

    len = list_len_a(first_a);
    if(len < 2)
        return ;
    while(len-2 > i)
    {
        (first_a) = (first_a)->next;
        i++;
    }
    valswap = (first_a)-> val; // keep the head-1 val temporarily
    /*ft_printf("Valswap Before : %d\n", valswap);
    ft_printf("Head Before : %d\n", (*head_a) -> val);*/
    (first_a) -> val = (*head_a) -> val;
    (*head_a) -> val = valswap;
    /*ft_printf("Valswap After : %d\n", (first_a) -> val);
    ft_printf("Head after : %d\n", (*head_a) -> val);*/
}

void sb(stack_b **head_b, stack_b *first_b)
{
    int len;
    int valswap;
    int i = 0;

    len = list_len_b(first_b);
    if(len < 2)
        return ;
    while(len-2 > i)
    {
        first_b = first_b->next;
        i++;
    }
    valswap = first_b -> val; // keep the head-1 val temporarily
    /*ft_printf("Valswap Before : %d\n", valswap);
    ft_printf("Head Before : %d\n", (*head_b) -> val);*/
    first_b -> val = (*head_b) -> val;
    (*head_b) -> val = valswap;
    /*ft_printf("Valswap After : %d\n", first_b -> val);
    ft_printf("Head after : %d\n", (*head_b) -> val);*/
}

void ss(stack_a **head_a, stack_a *first_a, stack_b **head_b, stack_b *first_b) // execute both functions
{
    sa(head_a, first_a);
    sb(head_b, first_b);
}
