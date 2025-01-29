/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:55:50 by natferna          #+#    #+#             */
/*   Updated: 2024/12/31 09:55:50 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h> 

int *stack2array(t_stack *stack)
{
    int i;
    int *array;
    t_node *current;
    if (!stack || stack->size == 0)
        return NULL; 

    array = malloc(stack->size * sizeof(int));
    if (!array)
        return NULL; 

    current = stack->top;
    i=0;
    while(i<stack->size)
    {
        array[i] = current->value; 
        current = current->next; 
        i++;
    }

    return array; 
}
int partition(int *array, int size)
{
    int pivot;
    int i;                 
    int j;                  
    int temp;

    pivot = array[size - 1];
    i = -1;
    j = 0;
    while (j < size - 1) {
        if (array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        j++;
    }
    temp = array[i + 1];
    array[i + 1] = array[size - 1];
    array[size - 1] = temp;
    return i + 1;
}
void quicksort(int *array, int size)
{
    int part_index; 

    if (size < 2)
        return; 
    part_index = partition(array, size);
    quicksort(array, part_index);
    quicksort(array + part_index + 1, size - part_index - 1); 
}


