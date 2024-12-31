/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:47:03 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 20:47:03 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void swap(t_stack *stack)
{
    t_node *first ;
    t_node *second;
    if (stack->size < 2)
        return; // No se puede hacer swap si hay menos de 2 elementos

    first= stack->top;
    second = first->next;

    first->next = second->next;
    second->next = first;
    stack->top = second; // El segundo nodo ahora es el "top"
}
void sa(t_stack *a, t_stack *b,t_log *log)
{
    swap(a);
    if (log)
        add_step(log,"sa");
    else
    {
        ft_printf("sa:\n");
        print_stacks(a,b);
    }

}

void    sb(t_stack *a, t_stack *b,t_log *log)
{
    swap(b);
    if (log)
        add_step(log,"sb");
    else
    {
        ft_printf("sb:\n");
        print_stacks(a,b);
    }
}

void    ss(t_stack *a, t_stack *b,t_log *log)
{
    swap(a);
    swap(b);
    if (log)
        add_step(log,"ss");
    else
    {
        ft_printf("ss:\n");
        print_stacks(a,b);
    }
}
