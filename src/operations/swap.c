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

void sa(t_stack *a) 
{
    if (a->size < 2)
        return; // No se puede hacer swap si hay menos de 2 elementos

    t_node *first = a->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    a->top = second; // El segundo nodo ahora es el "top"
}

void    sb(t_stack *b)
{
    if (b->size < 2)
        return; // No se puede hacer swap si hay menos de 2 elementos

    t_node *first = b->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    b->top = second; // El segundo nodo ahora es el "top"
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
