/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:51:00 by natferna          #+#    #+#             */
/*   Updated: 2025/01/02 12:51:00 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

t_node *get_last(t_stack *stack)
{
    t_node *current; 
    
    if (!stack || !stack->top)
        return NULL;    
    current = stack->top;
    while (current->next) {       
        current = current->next;
    }
    return current;               
}

t_node *get_second_last(t_stack *stack)
{
    t_node *current; 
    if (!stack || !stack->top) 
        return NULL; 
    current = stack->top;
    while (current->next && current->next->next) 
            current=current->next;
    return current; 
}
int locate(t_stack *stack,int index)
{
    t_node *current;
    int pos;
    current=stack->top;
    pos=0;
    while(current)
    {
        if(current->index==index)
            break;
        pos++;
        current=current->next;
    }
    return pos;
}
int near_high(t_stack *stack,int target)
{
    int near;
    int diff;
    int index;
    t_node *current;
    current=stack->top;
    near=max_index(stack);
    while (current)
    {
        index=current->index;
        diff=index-target;
        if(diff>0 && near>index)
            near=index; 
        current=current->next;
    }
    return near;
}