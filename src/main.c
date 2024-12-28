/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:28:16 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 21:28:16 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    
    // Comprobar si no hay argumentos
    if (argc == 1)
        return 0;
    
    // Verificar y cargar los argumentos en el stack_a
    ft_printf("%d,%s\n",argc,argv);
    if (!parse_arguments(argc, argv, &stack_a))
    {
        write(2, "Error\n", 6);  // Escribir mensaje de error en stderr
        return 1;
    }

    // Ejecutar algoritmo para ordenar stack_a
    if (is_sorted(stack_a))
        return 0;  // Si ya está ordenado, no hacer nada

    // En este ejemplo, llamamos a una función que optimiza las operaciones.
    // Podrías desarrollar tu propio algoritmo de ordenación aquí.
    sort_stack(&stack_a, &stack_b);
    
    // Liberar memoria de los stacks
    free_stack(stack_a);
    free_stack(stack_b);
    
    return 0;
}