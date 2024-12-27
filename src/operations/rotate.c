/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:51:17 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 20:51:17 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ra(t_stack *a)
{
    if (a->size < 2)
        return; // No se puede rotar si hay menos de 2 elementos

    t_node *first = a->top;
    t_node *second = first->next;

    // Encuentra el último nodo
    t_node *last = first;
    while (last->next != NULL) {
        last = last->next;
    }

    // Hacemos la rotación
    a->top = second;       // El segundo nodo es ahora el "top"
    last->next = first;          // El último nodo apunta al primer nodo
    first->next = NULL;          // El primer nodo ahora es el último
}

void    rb(t_stack *b)
{
    if (b->size < 2)
        return; // No se puede rotar si hay menos de 2 elementos

    t_node *first = b->top;
    t_node *second = first->next;

    // Encuentra el último nodo
    t_node *last = first;
    while (last->next != NULL) {
        last = last->next;
    }

    // Hacemos la rotación
    b->top = second;       // El segundo nodo es ahora el "top"
    last->next = first;          // El último nodo apunta al primer nodo
    first->next = NULL;          // El primer nodo ahora es el último
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
