/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:43:00 by natferna          #+#    #+#             */
/*   Updated: 2025/01/02 12:43:00 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void radix_sort(t_stack *a,t_stack *b,t_log *log)
{
    int max_bits;
    int bit;
    bit=0;
    max_bits=get_max_bits(a);
    while (bit<max_bits)
    {
        
        while(stackrem(a,bit,0)) //Pasar todos los valores de un
            atob(a,b,log,bit);
        while(b->top) //Devolver del stack temporal todos los valores
            pb(a,b,log); //Incluye ordenacion
        bit++;
    }
}

int prepare_next(t_stack *stack,int ascending)
{
    int current;
    int last;
    int next;
    int def;
    if(!stack->top||stack->size<2)
        return 0; //no need to do anything
    def= ascending ? INT_MAX : INT_MIN;
    current=stack->top->index;
    next=stack->top->next ? stack->top->index : def;
    last=get_last(stack) ? get_last(stack)->index : def;
    if((current>next) & ascending) //Head needs to be moved 
        return((current<last) & ascending)+2; //If lower than bottom, swap (3). Otherwise rotate (2)
    else if((current>last) & ascending)// Last must be pushed upwards, reverse rotate (1)
        return 1;
    else
        return 0; //No preparation needed
}
int best_rotation(t_stack *stack,int position, int bit,int higher)
{
    t_node *current;
    int dup;
    int i;
    int valid_value;
    dup=0;
    i=0;
    valid_value=higher ? INT_MIN:INT_MAX;
    current=stack->top;
    while (current)
    {
        if(get_bit(current->value,position)==bit)
            if((higher && current->value > valid_value) || (!higher && current->value < valid_value) || current->value==valid_value)
            {
                valid_value=current->value;
                dup=i;
            }
        current = current->next;
        i++;
    }
    return(dup > stack->size/2);
    //Devuelve 1 si hay que hacer reverse rotate
}
