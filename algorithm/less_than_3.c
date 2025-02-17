#include "../push_swap.h"

// linked min with atoi.


void less_than_3(stack_a **head_a) // funny sort with dumb reflexion
{
    int val_tmp;
    int i;
    stack_a *tmp;

    if (!head_a || !(*head_a)->prev || (*head_a)->prev->prev->prev->prev) // Check if there is 3 Nodes max
    {    ft_printf("hey");
        return;}
    i = 2; // Need to improve !!!!!
    tmp = (*head_a);
    while (i)
    {
        ft_printf("hey");
        while((*head_a)->prev)
        {
                ft_printf("Node before change :%d | %d", (*head_a)->val, (*head_a)->prev->val);
                if((*head_a)->val < (*head_a)->prev->val) // if current < previous
                {
                    val_tmp = (*head_a)->val; // Save the current val as tmp
                    (*head_a)->val = (*head_a)->prev->val; // Current now = the prev one
                    (*head_a)->prev->val = val_tmp; // Prev = Tmp (Old Current) with tmp
                }
                ft_printf(" - After :%d | %d\n", (*head_a)->val, (*head_a)->prev->val);
                *head_a = (*head_a)->prev; // Go to Prev node
        }
        (*head_a) = tmp; // 
        i--;
    }
}