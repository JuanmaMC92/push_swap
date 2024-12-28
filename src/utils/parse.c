/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:48:25 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 21:48:25 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int parse_arguments(int argc, char *argv[], t_stack *stack)
{
    int i;
    int num;
    for (i = 1; i < argc; i++)
    {
        if (!is_integer(argv[i]))  // Verifica si el argumento es un número entero
            return 0;
        num = ft_atoi(argv[i]);
        if (is_duplicate(stack, num))  // Verifica si el número ya existe en el stack
            return 0;
        push(stack, num);  // Agrega el número al stack
    }
    return 1;
}
int is_integer(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;  // Soporta números negativos y positivos
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;  // No es un número entero
        i++;
    }
    return 1;  // Es un número entero válido
}

int is_duplicate(t_stack *stack, int num)
{
    t_node *current;

    if (!stack || !stack->top)
        return (ft_printf("Error: stack or stack->top is NULL\n"),0); 
    current = stack->top; 
    while (current)
    {
        if (current->value == num)
            return 1;
        current = current->next;  
    }
    return 0;
}
