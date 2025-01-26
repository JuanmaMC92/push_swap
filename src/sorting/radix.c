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
    
    int mask;
    int bit_count;
    int bit;
    t_node *current;
    
    mask=1;


    bit_count=get_max_bits(a);
    bit=1;
    while(bit <= bit_count)
    {
        while(stackrem(a,bit,!mask))
        {
            current=a->top;
            if(get_bit(current->index,bit)== mask)
            {
                ra(a,b,log);
                /*
                current=b->top;
                if(current->next && current->index > current->next->index)
                    sb(a,b,log);
                */
            } 
            else
                pb(a,b,log);
            
                            
        }
        ft_printf("%d bit:\n",bit);
        ft_printf("A to B\n");
        print_stacks(a,b);

        while(b->size>0)
        {
            pa(a,b,log);
            /*
            current=a->top;
            if(current->next && current->index > current->next->index)
                sa(a,b,log);
            */
        }
        bit++;
        if(is_sorted(a))
            break;
    }

}