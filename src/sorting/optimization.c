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
    t_node *current;
    bit=0;
    max_bits=0;
    max_bits=get_max_bits(a);
    current=a->top;
    while(current)
    {
        ft_printf("%d [%d]\n",current->value,current->index);
        current=current->next;
    }
    while (bit<max_bits)
    {
        
        while(stackrem(a,bit,0)||a->size>3) //Pasar todos los valores de un 
            atob(a,b,log,bit);
        /*if(a->size<4)
            sort_three(a,b,log);
        */
        ft_printf("%d bit:\n",bit);
        print_stacks(a,b);
        while(b->top) //Devolver del stack temporal todos los valores
        {    
            //;
            pa(a,b,log); //Incluye ordenacion
            prepare_next(a,1);
        }
        
        codestop();
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
    ft_printf("Current: %d, Next: %d, Last: %d\n", current, next, last);
    if ((ascending && current > next) || (!ascending && current < next))  //Head needs to be moved 
        return ((ascending && current < last) || (!ascending && current > last))+2; //If lower than bottom, swap (3). Otherwise rotate (2)
    else if((ascending && current > last) || (!ascending && current < last))// Last must be pushed upwards, reverse rotate (1)
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
    valid_value= higher ? INT_MIN:INT_MAX;
    current=stack->top;
    while (current)
    {
        if(get_bit(current->value,position)==bit)
            if((higher && current->index > valid_value) || (!higher && current->index< valid_value) || current->index!=valid_value)
            {
                valid_value=current->index;
                dup=i;
            }
        current = current->next;
        i++;
    }
    return(dup > stack->size/2);
    //Devuelve 1 si hay que hacer reverse rotate
}
