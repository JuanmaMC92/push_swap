/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:51:45 by natferna          #+#    #+#             */
/*   Updated: 2025/01/02 11:51:45 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int get_bit(int number, int position)
{
    if(position<=bit_count(number))
        return (number >> position) & 1;
    return 0;
}
int bit_count(int number)
{
    int count;
    count=0;
    while (number > 0)
    {
        number>>=1;
        count++;  
    }
    return count;
}
int get_max_bits(t_stack *stack)
{
    t_node *current;
    int max_bits;
    int i;
    map_stack(stack);
    current=stack->top;
    // Determina el número máximo de bits
    while (current) {
        i = bit_count(current->index);
        if (i > max_bits)
            max_bits = i;
        current = current->next;
    }
    return max_bits;
}
int stackrem(t_stack *stack,int position, int bit)
{
    int count;
    t_node *current;
    count=0;
    if(stack->top)
    {
        current=stack->top;
        while (current)
        {
            if (get_bit(current->index,position) & bit)
                count++;
            current=current->next;
        }
    }
    return count;
}
