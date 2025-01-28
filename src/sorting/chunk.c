/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:26:40 by natferna          #+#    #+#             */
/*   Updated: 2025/01/28 18:26:40 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void chunk_split(t_stack *a, t_stack *b,t_log *log ,int chunk_size)
{

    int chunk_count = 0;
    int rem;
    int moved;

    while (a->size>0) {
        moved=0;
        rem=a->size;
        while(rem--)
        {
            if (a->top->index / chunk_size == chunk_count)
            {
                pb(a,b,log);// Envía a stack_b
                moved=1;
            }
            else
                ra(a,b,log); // Rota para encontrar el siguiente elemento del chunk
        }
        // Si no quedan más elementos en el chunk actual, pasa al siguiente
        if (!moved)
            chunk_count++;
    }
}
int max_idx(t_stack *stack)
{
    t_node *current;
    int max;
    max=0;
    current=stack->top;
    while (current)
    {
        if(current->index>max)
            max=current->index;

        current=current->next;
    }
    return (ft_printf("Next to A:%d\n",max),max);
}
void chunk_merge(t_stack *a, t_stack *b,t_log *log)
{
    int n_idx;
    while(b->size>0)
    {
        n_idx=max_idx(b);
        while(b->top->index!=n_idx && b->size!=1)
            rb(a,b,log);
        pa(a,b,log);
    }
}
void chunk_sort(t_stack *a, t_stack *b,t_log *log)
{
    int num_chunks;
    int chunk_size;
    num_chunks=5;
    chunk_size = (a->size + num_chunks - 1) / num_chunks;
    chunk_split(a,b,log,chunk_size);
    chunk_merge(a,b,log);
}
void proc_chunk_radix(t_stack *a, t_stack *b,t_log *log)
{
    int msb;
    int size;
    int bit;
    int index;

    msb=get_max_bits(a);
    
    
    bit=msb-1;
    while(bit>0)
    {
        size=a->size;
        while(size--)
        {
            index=a->top->index;
            if (((index>>bit)&1) == 0)
                pb(a, b, log);
            else
                ra(a, b, log);
        }
        bit--;
    }
    bit=0;
    while(bit<msb)
    {
        size=b->size;
        while(size--)
        {
            index=b->top->index;
            if (((index>>bit)&1) == 0)
                pa(a, b, log);
            else
                rb(a, b, log); 
        }
        bit++;
    
    }
    while (b->size > 0)
        pa(a,b,log);
}