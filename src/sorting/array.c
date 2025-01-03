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
    while(i<stack->size)
    {
        array[i] = current->value; // Copia el valor del nodo actual al arreglo
        current = current->next; 
        i++;
    }

    return array; // Devuelve el arreglo
}

void quicksort(int *array, int size) 
{
    int pivot;
    int i; 
    int j;
    int temp; 
    int partition_index; // Declarar todas las variables al inicio

    if (size < 2)
        return; // Caso base: si el tamaño es 1 o menos, ya está ordenado

    pivot = array[size - 1]; // Elegir el pivote
    i = -1;                  // Inicializar índice para los elementos menores
    j = 0;                   // Inicializar índice para iterar el arreglo

    while (j < size - 1) { // Iterar por los elementos antes del pivote
        if (array[j] < pivot) {
            i++;
            // Intercambiar array[i] y array[j]
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        j++;
    }

    // Colocar el pivote en su posición correcta
    temp = array[i + 1];
    array[i + 1] = array[size - 1];
    array[size - 1] = temp;

    partition_index = i + 1;

    // Ordenar recursivamente las dos mitades
    quicksort(array, partition_index);                  // Izquierda del pivote
    quicksort(array + partition_index + 1, size - partition_index - 1); // Derecha del pivote
}

void map_stack(t_stack *stack)
{
    int *array;
    int i;
    t_node *current;
    array=stack2array(stack);
    if(array)
    {   
        current=stack->top;
        while(current)
        {
            i=0;
            while(i < stack->size)
            {    
                if(current->value==array[i])
                {
                    current->index =i;
                    break;
                }
                i++;
            }
            current=current->next;
        }
    }
}

int find_median(t_stack *stack)
{
    int *array;  // Declaración de puntero para el arreglo
    int median;  // Declaración de la variable para la mediana

    if (!stack || stack->size == 0) {
        return INT_MIN; // Retorna un valor especial en caso de error
    }

    // Convierte la pila a un arreglo
    array = stack2array(stack);
    if (!array) {
        return INT_MIN; // Error al convertir
    }

    // Ordena el arreglo
    quicksort(array, stack->size);

    // Encuentra el valor medio
    median = array[stack->size / 2];

    // Libera el arreglo
    free(array);

    return median;
}