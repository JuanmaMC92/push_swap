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
                sync_rot(a,b,log,1); //Choose direction and sync if possible
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

int opt_rot(t_stack *a,int position)
{
    t_node *current;
    int head_count;
    int rear_count;
    int i;

    i=0;
    head_count=0;
    rear_count=0;
    current=a->top;
    while(current){
        if(get_bit(current->index,position)==0)
        {
            if(i < a->size/2)
                head_count++;
            else
                rear_count++;
        }
        current=current->next;
        i++;
    }
    ft_printf("Top elements:%d vs Bottom elements:%d\n",head_count,rear_count);
    return head_count<=rear_count;
}
void sync_rot(t_stack *a,t_stack *b,t_log *log,int dir)
{
    int sync;
    sync=(b->size>1 && b->top->index<get_last(b)->index);
    if(dir)
    {
        if(sync)
            rr(a,b,log);
        else
            ra(a,b,log);
    }
    else
    {
        if(sync)
            rrr(a,b,log);
        else
            rra(a,b,log);
    }
}
void proc_2bit_radix(t_stack *a, t_stack *b, t_log *log)
{
    int bit;
    int bit_count;
    int size;
    int group;
    size = a->size;
    bit_count = 0;
    while (((size - 1) >> bit_count) != 0)
        bit_count++;

    bit = 0;
    while (bit < bit_count) 
    {
        size = a->size;
        while(size-- && !is_sorted(a))
        {
            group=(a->top->index>>bit)&3;
            
            if(group<2)
                {
                    pb(a,b,log);
                    if(group==1 && b->size>1)
                        rb(a,b,log);
                }
            else
                sync_rot(a,b,log,1);
        }
        ft_printf("Processing bits %d-%d:\n", bit, bit + 1);
        print_stacks(a, b);
        /*
       while (b->size>0)
       {
        pa(a,b,log);
        if(b->size>1)
            {
                rrb(a,b,log);
                pa(a,b,log);
            }
       }
       */
       while (b->size>0)
       {
        if(b->size>1)
            rb(a,b,log);
        pa(a,b,log);
       }


        //radix_btoa(a,b,log,bit);
        bit+=2;
    }
}
void radix_btoa(t_stack *a,t_stack *b,t_log *log, int bit)
{
    int size;
    size=b->size;
    while(size--)
    {
        if(((b->top->index>>bit)&3) == 1)
            pa(a,b,log);
        else
            rb(a,b,log);
    }
    while(b->size>0)
        pa(a,b,log);        
}


void proc_radix_2bits(t_stack *a, t_stack *b, t_log *log)
{
    int bit;       // Posición inicial de los bits
    int bits;
    int size;      // Tamaño actual de la pila
    int group;     // Grupo actual (00, 01, 10, 11)
    int bit_count; // Número total de bits necesarios

    size = a->size;
    bit_count = 0;

    // Calcula el número de bits necesario
    while (((size - 1) >> bit_count) != 0)
        bit_count++;

    bit = 0;

    // Itera procesando 2 bits a la vez
    while (bit < bit_count) {
        group = 0;

        // Procesa los 4 grupos: 00, 01, 10, 11
        while (group < 4) {
            size = a->size;
            while (size-- && !is_sorted(a)) {
                bits = get_bits(a->top->index, bit, 2); // Obtén los 2 bits desde `bit`

                if (bits != group) {
                    pb(a, b, log); // Mueve a `b` si pertenece al grupo actual
                } else {
                    sync_rot(a, b, log,1); // Rota en la dirección óptima
                }
            }

            // Mueve el grupo actual de vuelta a `a`
            while (b->size > 0) {
                pa(a, b, log);
            }

            group++;
        }

        ft_printf("After processing bits %d-%d:\n", bit, bit + 1);
        print_stacks(a, b);

        bit += 2; // Avanza 2 bits
    }
}


