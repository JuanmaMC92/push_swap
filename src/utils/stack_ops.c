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
    t_node *current; // Empieza desde el nodo superior
    
    if (!stack || !stack->top)
        return NULL;    // Si la pila está vacía, retorna NULL
    current = stack->top;
    while (current->next) {       // Recorre hasta el último nodo
        current = current->next;
    }
    return current;               // Retorna el último nodo
}

t_node *get_second_last(t_stack *stack)
{
    t_node *current; // Empieza desde el nodo superior
    if (!stack || !stack->top) 
        return NULL; // Si no hay al menos dos nodos, retorna NULL
    current = stack->top;
    while (current->next && current->next->next) // Recorre hasta el penúltimo nodo
            current=current->next;
    return current; // Retorna el penúltimo nodo
}