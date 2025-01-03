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
void sort_stack(t_stack *a, t_stack *b,t_log *log)
{
    while(!is_sorted(a))
        stack_sort(a,b,log);
    print_log(log);
    ft_printf("Sorted:\n");
    print_stack(a);
    ft_printf("|A\n");
}
void stack_sort(t_stack *a, t_stack *b,t_log *log)
{
    ///Main sorting algorithm
    if(a->size>3)
        radix_sort(a,b,log);
    else
        sort_three(a,b,log);
}
void sort_three(t_stack *a,t_stack *b,t_log *log)
{
    t_node *current;
    t_node *last;
    
    while(!is_sorted(a))
    {    
        current = a->top;
        last = current->next;
        while (last->next)
            last = last->next;
        if (current->value > current->next->value)
                sa(a, b, log);
        else if (last->value < current->value)
                rra(a, b, log);
        else 
                ra(a, b, log);
    }

}
