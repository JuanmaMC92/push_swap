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
            return (ft_printf("Node:%d(%d) > Next: %d (%d)\n",current->value,current->index,current->next->value,current->next->index),0); 
        current = current->next;
    }
    return 1; 
}
void sort_stack(t_stack *a, t_stack *b,t_log *log)
{
    if(!is_sorted(a) && a->size>1)
        stack_sort(a,b,log);
    print_log(log);
    ft_printf("<<%s>>\n",is_sorted(a)?"Sorted successfully":"Unable to sort");
    print_stack(a);
    ft_printf("|A\n");
}
void stack_sort(t_stack *a, t_stack *b,t_log *log)
{
    
    if (a->size==2)
        sa(a,b,log);
    else if (a->size<4)
        sort_three(a,b,log);
    
    else if (a->size<6)
        sort_five(a,b,log);
    
    else
        proc_btoa(a,b,log);
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
    ft_printf("Sort-five Strategy-%d\n",a->size);
    while (a->size > 3) 
    {
        ft_printf("Top item:%d(%d)\n",a->top->value,a->top->index);
        if (a->top->index ==min_index(a))
            pb(a, b, log); 
        else
            ra(a, b, log); 
        
    }
    sort_three(a, b, log); 
    ft_printf("A sorted, return from B\n");
    if(is_sorted(b))
        sb(a, b, log); 
    i=2;
    while(i--)
        pa(a, b, log); 
}
