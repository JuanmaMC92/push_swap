/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:51:19 by natferna          #+#    #+#             */
/*   Updated: 2024/12/29 00:51:19 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include <stdlib.h>
#include <stdio.h>

void copy_and_sort_stack(t_stack *stack, int **sorted)
{
    t_node *current = stack->top;
    int *arr;
    int i = 0;

    arr = (int *)malloc(sizeof(int) * stack->size);
    if (!arr)
        return;
    while (current)
    {
        arr[i++] = current->value;
        current = current->next;
    }
    for (int j = 0; j < stack->size - 1; j++)
    {
        for (int k = j + 1; k < stack->size; k++)
        {
            if (arr[j] > arr[k])
            {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }
    *sorted = arr;
}

int calculate_moves(t_stack *stack, int value, int *sorted) {
    int moves = 0;
    int size = stack->size;

    // Buscar la posición del valor en el arreglo sorted
    int position_in_sorted = 0;
    for (int i = 0; i < size; i++) {
        if (sorted[i] == value) {
            position_in_sorted = i;
            break;
        }
    }

    // Calcular el número de movimientos hacia la cima
    if (position_in_sorted <= size / 2) {
        // Movimiento hacia arriba (ra)
        moves = position_in_sorted;
    } else {
        // Movimiento hacia abajo (rra)
        moves = -(size - position_in_sorted);
    }

    return moves;
}


void defsort_stack(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current ;
    int *sorted;
    int moves;
    current= stack_a->top; 
    moves= 0;
    sorted=NULL;
    copy_and_sort_stack(stack_a,&sorted);
    while (current != NULL) {
        // Obtener el número de movimientos para colocar el valor actual en la cima
        moves = calculate_moves(stack_a, current->value, sorted);
        if (moves > 0) {
            for (int i = 0; i < moves; i++) {// Si es positivo, realiza movimientos hacia arriba (ra)
                ra(stack_a);  // Rotar hacia arriba
            }
        } else if (moves < 0) {
            for (int i = 0; i < -moves; i++) {// Si es negativo, realiza movimientos hacia abajo (rra)
                rra(stack_a);  // Rotar hacia abajo
            }
        }
        pb(stack_a,stack_b);  // Mover de a hacia b (push b)
        current = current->next;
    }   
    while (stack_b->top) {// Ahora que el stack 'b' tiene los elementos ordenados, podemos ir devolviendo a 'a'
        pa(stack_a,stack_b);  // Mover de b hacia a
    }
}

