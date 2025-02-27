#include "../push_swap.h"

// linked min with atoi.


void less_than_3(stack_a **head_a) // funny sort with dumb reflexion
{
    int i;
    stack_a *top;

    if (!head_a || !(*head_a)->prev || (*head_a)->prev->prev->prev) // Check if there is 3 Nodes max
        return;

    i = 2; // Need to improve !!!!!
    top = (*head_a);
    while (i)
    {
        while((*head_a)->prev)
        {
                if((*head_a)->val < (*head_a)->prev->val) // if current < previous
                {
                    sa(head_a);
                    ft_printf("sa");
                }
                *head_a = (*head_a)->prev; // Go to Prev node
        }
        (*head_a) = top; // 
        i--;
    }
}

