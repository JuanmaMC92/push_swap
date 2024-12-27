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

void    rra(t_stack *a)
{
    if (a->size < 2)
        return; // No se puede hacer reverse rotate si hay menos de 2 elementos

    t_node *last = a->top;
    t_node *second_last = NULL;

    // Encontramos el penúltimo nodo
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    // Desconectamos el último nodo
    second_last->next = NULL;

    // El último nodo se convierte en el nuevo "top"
    last->next = a->top;
    a->top = last;
}

void    rrb(t_stack *b)
{
    if (b->size < 2)
        return; // No se puede hacer reverse rotate si hay menos de 2 elementos

    t_node *last = b->top;
    t_node *second_last = NULL;

    // Encontramos el penúltimo nodo
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    // Desconectamos el último nodo
    second_last->next = NULL;

    // El último nodo se convierte en el nuevo "top"
    last->next = b->top;
    b->top = last;
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
