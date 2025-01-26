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
        return NULL; // Devuelve NULL si la pila está vacía o no existe

    array = malloc(stack->size * sizeof(int));
    if (!array)
        return NULL; // Devuelve NULL si la memoria no pudo ser asignada

    current = stack->top;
    i=0;
    while(i<stack->size)
    {
        array[i] = current->value; // Copia el valor del nodo actual al arreglo
        current = current->next; 
        i++;
    }

    return array; // Devuelve el arreglo
}

int partition(int *array, int size)
{
    int pivot;
    int i;                  // Índice para los elementos menores
    int j;                   // Índice para recorrer el arreglo
    int temp;
    pivot = array[size - 1]; // Elegir el pivote
    i = -1;
    j = 0;
    // Mover los elementos menores que el pivote al lado izquierdo
    while (j < size - 1) {
        if (array[j] < pivot) {
            i++;
            // Intercambiar array[i] y array[j]
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        j++;
    }

    // Colocar el pivote en su lugar correcto
    temp = array[i + 1];
    array[i + 1] = array[size - 1];
    array[size - 1] = temp;
    return i + 1; // Retorna el índice del pivote
}
void quicksort(int *array, int size)
{
    int part_index; // Declarar todas las variables al inicio

    if (size < 2)
        return; // Caso base: si el tamaño es 1 o menos, ya está ordenado
    // Dividir el arreglo y obtener el índice del pivote
    part_index = partition(array, size);

    // Ordenar recursivamente las dos mitades
    quicksort(array, part_index);                  // Izquierda del pivote
    quicksort(array + part_index + 1, size - part_index - 1); // Derecha del pivote
    /*
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    */
}


