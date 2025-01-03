/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:50:44 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 20:50:44 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

void    push(t_stack *stack, int value)
{
    t_node *new_node;
    new_node= malloc(sizeof(t_node));
    if (!new_node)
        return; 
    new_node->value = value;
    new_node->index=0;
    if(stack->top)
        new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}
int pop(t_stack *stack)
{
    t_node *temp ;
    int value;
    if (stack->size == 0)
        return -1; // Error: stack vacío
    
    temp = stack->top;
    value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}
void    pa(t_stack *a, t_stack *b,t_log *log)
{
if (b->size == 0)
        return; // No se puede hacer push si `b` está vacío

    int value = pop(b); // Sacamos el primer elemento de `b`
    push(a, value);     // Lo metemos en `a`
    if (log)
        add_step(log,"pa");
    else
    {
        ft_printf("pa:\n");
        print_stacks(a,b);
    }
}

void    pb(t_stack *a, t_stack *b,t_log *log)
{
    if (a->size == 0)
        return; // No se puede hacer push si `a` está vacío

    int value = pop(a); // Sacamos el primer elemento de `a`
    push(b, value);     // Lo metemos en `b`
    if (log)
        add_step(log,"pb");
    else
    {
        ft_printf("pb:\n");
        print_stacks(a,b);
    }

}
