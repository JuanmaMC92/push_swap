/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:11:51 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 21:11:51 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


t_stack *create_stack()
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack){
        ft_printf("Error: Could not allocate memory for stack\n");
        return NULL; // Manejo de error
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void    free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current) {
        t_node *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    printf("Stack: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
