/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:48:24 by natferna          #+#    #+#             */
/*   Updated: 2025/01/25 21:48:24 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void proc_radix(t_stack *a,t_stack*b,t_log *log)
{    
    t_node *current;
    int bit;
    int rot;// Not used
    int size;
    int bit_count;

    size=a->size; 
    bit_count=0;
    while(((size-1)>>bit_count)!=0)
        bit_count++;
    bit=0;
    while(bit < bit_count)
    {
        //while(stackrem(a,bit,!mask))
        size=a->size;
        rot=0;// Not used
        while(size-- && !is_sorted(a))
        {
            current=a->top;
            if(get_bit(current->index,bit)== 1)
            {
                ra(a,b,log);
                rot++; // Not used
            } 
            else
            {
                pb(a,b,log);
            }            
        }
        ft_printf("%d bit:\n",bit);
        ft_printf("Rotations:%d\n Remaining: %d\n",rot,size);
        /*
        if(size>0 && rot<size){
            rot++;
            while(rot--)
                rra(a,b,log);
        }else if(size>0 && rot>=size){
            size++;
            while(size--){
                ra(a,b,log);
            }
        }
        */



        ft_printf("A to B\n");
        print_stacks(a,b);
        //radix_btoa(a,b,log,bit+1,bit_count);
        while(b->size>0)
        {
            pa(a,b,log);
        }
        bit++;
    }
}

int restore_rot(int ra_count,int ra_rem)
{
    return (ra_count<=ra_rem);
}

void radix_btoa(t_stack *a,t_stack *b,t_log *log,int bit,int max_bits)
{
    int size;
    size=b->size;
    if(is_sorted(a))
    {
        while(b->size>0)
            pa(a,b,log);
    }
    else
    {
        while(size-- && bit<=max_bits)
        {
            if(get_bit(b->top->index,bit)==1)
            {
                rb(a,b,log);
            }
            else
                pa(a,b,log);
       }
    }
    
    
        
}