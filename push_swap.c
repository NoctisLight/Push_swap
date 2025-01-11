/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42-angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:51:43 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/30 16:57:28 by fben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isnum(char *s) // args control
{
    int i = 0;
    while(s[i])
	{
        if ((s[i] < 48 || s[i] > 57) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
		    return (0);
        i++;
    }
	return (1);
}

void check_ifok(char *all_in_one)
{
    char **tab;
    int i;
    stack_a *head_a;
    stack_a *first_a;
    stack_a *new_node;
    stack_b *head_b;
    stack_b *first_b;
    t_data *data;
    data = malloc(sizeof(t_data));
    tab = ft_split(all_in_one, ' '); // split each numbers in a tab ready to be send to atoi
    head_a = malloc(sizeof(stack_a));
    head_b = malloc(sizeof(stack_b));
    first_a = head_a;
    first_b = head_b;
    
    data->max = 0;
    i = 0;
    while(tab[i]) // send each number to atoi  
    {   
        new_node = ft_atoi(first_a, head_a, tab[i], &data); // try to create a new node.
        if(new_node)
            head_a = new_node;
        else{
            ft_printf("Error\n");
            return ;
        }
        i++;
    }
    first_a = first_a->next; // skip the random 0 at the beginning of the list
    //first_b = first_b->next;
    /*head = first_a; // reset head to first

    while(head) // simple while to print all of my nodes
    {
        printf("%d\n", head->val);
        head = head->next;
    }*/

    // THIS ZONE WILL BE USED TO CHECK IF OUR MOVES ARE WORKING / DO SOME TESTS
    //head = first_a; // reset head to first again to test X move
    ft_printf("\nTest Move :\n\n");
    //head_a = first_a;
    head_b = first_b;
    ft_printf("\nList A :\n");
    /*while(head_a)
    {
        printf("%d\n", head_a->val);
        head_a = head_a->next;
    }*/
    ft_printf("\nList B :\n");
    //head_a = first_a;
    pb(&head_a, &head_b, first_a);
    ft_printf("\nList A :\n");
    head_a = first_a;
    while(head_a)
    {
        printf("%d\n", head_a->val);
        head_a = head_a->next;
    }
    ft_printf("\nList B :\n");
    while(head_b)
    {
        printf("%d\n", head_b->val);
        head_b = head_b->next;
    }
    free(tab);
    ft_printf("\n\nThe highest number is : %d", (*data).max);
}

int main(int agc, char **agv)
{
    int i;
    static char *all_in_one;  // used to create one and unique quote for all agv

    if(agc < 2)
    {
        ft_printf("Error\n");
        return (0);
    }
    i = 1;
    while(agv[i])
    {
        all_in_one = ft_strjoin(all_in_one, agv[i]);
        if(i < agc-1)
            all_in_one = ft_strjoin(all_in_one, " ");
        i++;
    }
    if(!ft_isnum(all_in_one)) // error if wrong char in string
        ft_printf("Error\n");
    else 
        check_ifok(all_in_one);
}
