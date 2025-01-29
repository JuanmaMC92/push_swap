/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:52:28 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 20:52:28 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void reverse(t_stack *stack)
{
    t_node *last;
    t_node *second_last;

    
    if (stack->size < 2)
        return;

    last = stack->top;
    
    while (last->next)
        last = last->next;

    second_last = stack->top;
    
    while (second_last->next != last)
        second_last = second_last->next;

    
    second_last->next = NULL;

    
    last->next = stack->top;
    stack->top = last;
}
void    rra(t_stack *a, t_stack *b,t_log *log)
{
    reverse(a);
    if (log)
        add_step(log,"rra");
    else
    {
        ft_printf("rra:\n");
        print_stacks(a,b);
    }
}

void    rrb(t_stack *a, t_stack *b,t_log *log)
{
     
    reverse(b);
    if (log)
        add_step(log,"rrb");
    else
    {
        ft_printf("rrb:\n");
        print_stacks(a,b);
    }
}

void    rrr(t_stack *a, t_stack *b,t_log *log)
{
    reverse(a);
    reverse(b);
    if (log)
        add_step(log,"rrr");
    else
    {
        ft_printf("rrr:\n");
        print_stacks(a,b);
    }
}
