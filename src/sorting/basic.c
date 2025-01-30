/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:21:53 by natferna          #+#    #+#             */
/*   Updated: 2024/12/28 21:21:53 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || stack->size <= 1) 
        return 1;

    current = stack->top;
    while (current && current->next)
    {
        if (current->index > current->next->index)
            return (0); 
        current = current->next;
    }
    return 1; 
}
void sort_stack(t_stacksys *stacks)
{
    if(!is_sorted(stacks->a) && stacks->a->size>1)
        stack_sort(stacks);
    print_log(stacks->log);
    ft_printf("<<%s>>\n",is_sorted(stacks->a)?"Sorted successfully":"Unable to sort");
    print_stack(stacks->a);
    ft_printf("|A\n");
}
void stack_sort(t_stacksys *stacks)
{
    
    if (stacks->a->size==2)
        sa(stacks->a,stacks->b,stacks->log);
    else if (stacks->a->size<4)
        sort_three(stacks->a,stacks->b,stacks->log);
    
    else if (stacks->a->size<6)
        sort_five(stacks->a,stacks->b,stacks->log);
    
    else
        proc_btoa(stacks);
}
void sort_three(t_stack *a,t_stack *b,t_log *log)
{
    int head;
    int next;
    int last;
    

    while(!is_sorted(a))
    {
        head=a->top->index;
        next=a->top->next->index;
        last=get_last(a)->index;
        if(head>next)
        {
            if(head>last)
                ra(a,b,log);
            else
                sa(a,b,log);
        }
        else
            rra(a,b,log);
    }
}
void sort_five(t_stack *a, t_stack *b, t_log *log)
{
    int i;
    while (a->size > 3) 
    {
        if (a->top->index ==min_index(a))
            pb(a, b, log); 
        else
            ra(a, b, log); 
        
    }
    sort_three(a, b, log); 
    if(is_sorted(b))
        sb(a, b, log); 
    i=2;
    while(i--)
        pa(a, b, log); 
}
