/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fben-ham <fben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:51:43 by fben-ham          #+#    #+#             */
/*   Updated: 2024/12/20 13:49:31 by fben-ham         ###   ########.fr       */
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
        if (s[i] == '-' && !((s[i-1] == '-' || s[i-1] == ' ') && (s[i+1] == '-' || (s[i+1] >= 48 && s[i+1] <= 57))))
            return (0);
        if (s[i] == '+' && !((s[i-1] == '+' || s[i-1] == ' ') && (s[i+1] == '+' || (s[i+1] >= 48 && s[i+1] <= 57))))
            return (0);
        i++;
    }
	return (1);
}

void check_ifok(char *all_in_one)
{
    char **tab;
    int i = 0;
    stack_a * head;
    stack_a * tmp;
    tab = ft_split(all_in_one, ' '); // split each numbers in a tab ready to be send to atoi
    //ft_printf("%s\n", tab[i]);
    head = malloc(sizeof(stack_a));

    stack_a *first = head;
    //head->next = NULL;
    while(tab[i])
    {    
        
        tmp = malloc(sizeof(stack_a));
        tmp -> val = ft_atoi(tab[i]);
        tmp -> next = NULL;
        head -> next = tmp;
        //printf("%d\n", head->val);
        head = head->next;
        i++;
    }
    head = first;
    while(head)
    {
        printf("%d\n", head->val);
        head = head->next;
    }
}

int main(int agc, char **agv)
{
    int i;
    static char *all_in_one;  // used to create one and unique quote for all agv

    if(agc == 1)
        return 0;
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
