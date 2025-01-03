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
    //int prep;
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
        
        while(stackrem(a,bit,0) && a->size>3) //Pasar todos los valores de un 
            atob(a,b,log,bit);
        if(a->size<4)
            sort_three(a,b,log);
        ft_printf("%d bit:\n",bit);
        ft_printf("A to B\n");
        print_stacks(a,b);
        while(b->top) //Devolver del stack temporal todos los valores
            pa(a,b,log);
        /*
        prep=prepare_next(a,1);
        if (prep)
        {    
            if(prep>2)
                sa(a,b,log);
            else if(prep>1)
                ra(a,b,log);
            else
                rra(a,b,log);
        }
        */
        ft_printf("B back to A\n");
        print_stacks(a,b);
        
        //codestop();
        bit++;
    }
}

int prepare_next(t_stack *stack,int ascending)
{
    int current;
    int last;
    int next;
    int def;
    if(!stack->top||stack->size<3)
        return 0; //no need to do anything
    def= ascending ? INT_MAX : INT_MIN;
    current=stack->top->index;
    next=stack->top->next ? stack->top->next->index : def;
    last=get_last(stack) ? get_last(stack)->index : def;
    ft_printf("Current: %d, Next: %d, Last: %d\n", current, next, last);
    print_stack(stack);
    ft_printf(" |size %d\n",stack->size);
    
    if ((current > next && ascending)||(current < next && !ascending))  //Head needs to be moved 
        {
            ft_printf("Head and next not sorted\n");
            return 2+((current <last && ascending)||(current >last && !ascending)); //If lower than bottom, swap (3). Otherwise rotate (2)
        }
    else if((current>last && ascending)||(current<last && !ascending))// Last must be pushed upwards, reverse rotate (1)
        {
        ft_printf("Head and last not sorted\n");
        return 1;
        }
    else
        return 0; //No preparation needed
}
int best_rotation(t_stack *stack,int position, int bit,int higher)
{
    t_node *current;
    int dup;
    int i;
    int best;
    dup=0;
    i=0;
    best= higher ? INT_MIN:INT_MAX;
    current=stack->top;
    while (current)
    {
        if(get_bit(current->index,position)==bit)
        {    
            if((higher && current->index >= best) || (!higher && current->index <= best) )
            {
                best=current->index;
                
                dup=i;
                ft_printf("Best:%d @ %d/%d\n",current->value,dup,stack->size);
            }
        }
        current = current->next;
        i++;
    }
    return(dup > stack->size/2);
    //Devuelve 1 si hay que hacer reverse rotate
}
