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

    if (!stack || stack->size <= 1) // Si el stack está vacío o tiene un solo elemento
        return 1;

    current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0; // Encontró un desorden, no está ordenado
        current = current->next;
    }
    return 1; // Está completamente ordenado
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    print_stack(*stack_a);
    print_stack(*stack_b);
}
