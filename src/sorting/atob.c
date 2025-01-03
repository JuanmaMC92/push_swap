/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:10:20 by natferna          #+#    #+#             */
/*   Updated: 2025/01/03 14:10:20 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"
#include <limits.h>

void atob(t_stack *a , t_stack *b, t_log *log,int bit)
{
    int prep;
    push_atob(a,b,log,bit);
    
    prep=prepare_next(b,0);
    ft_printf("b preparation (1:rrb/2:rb/3:sb):%d\n",prep);
    if (prep)
    {    
        if(prep>2)
            sb(a,b,log);
        else if(prep>1)
            rb(a,b,log);
        else
            rrb(a,b,log);
    }
    //print_stacks(a,b);
    //codestop();
}
void btoa(t_stack *a , t_stack *b, t_log *log)
{
    int prep;
    pa(a,b,log);
    
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
    //print_stacks(a,b);
    //codestop();
}
void push_atob(t_stack *a , t_stack *b, t_log *log,int bit)
{
    if(a->size < 2)
        return;
    if(prep_atob(a,b,log,bit))
        pb(a,b,log);
    else
        {
        print_stack(a);
        ft_printf("|A\n");
        if(best_rotation(a,bit,0,0)) //Rotate
        {
            if(b->top && b->top->index < get_last(b)->index)//Preparacion de A con rra,comprobar si B necesita un rrb
                rrr(a,b,log);
            else
                rra(a,b,log);
        }
        else
        {//If next valid (now first), move
            if(b->top && b->top->index> get_last(b)->index) //Rotation preferred
                rr(a,b,log);
            else if(b->top && b->top->next && b->top->index < b->top->next->index)
                ss(a,b,log);
            else
                ra(a,b,log);
        }
        ft_printf("After rotation:");
        print_stack(a);
        ft_printf("|A\n");
        }
    return;
}
int prep_atob(t_stack *a , t_stack *b, t_log *log,int bit)
{
    int a_move;
    if(!a->top)
        return 0; //Empty A, no move
    a_move=best_atob(a,bit);
    ft_printf("best move:%d (1:head/2:next/3:last)\n",a_move);
    if(a_move>1)// Top value is not valid, check if next or last are valid
    {
        if(a_move>2) // Last value, rra
        {//Si el ultimo valor (ahora el primero) es valido, mover
            if(b->top && b->top->index < get_last(b)->index)//Preparacion de A con rra,comprobar si B necesita un rrb
                rrr(a,b,log);
            else
                rra(a,b,log);
               
        }else // next value, decide if ra or sa
        {//If next valid (now first), move
            if(b->top && b->top->value > get_last(b)->value) //Rotation preferred
                rr(a,b,log);
            else if(b->top && b->top->next && b->top->value < b->top->next->value)
                ss(a,b,log);
            else
                ra(a,b,log);
        }
    }
    return a_move>0;
}
int best_atob(t_stack *a ,int bit)
{
    //Comprobar cual es el mejor valor - 0:Ninguno, 1:Primero,2:Siguiente, 3:Ultimo
    int next;
    int last;
    if(!get_bit(a->top->index,bit))
        return 1;// Primer valor (1)

    next=a->top->next ? a->top->next->index : INT_MAX;
    last=get_last(a) ? get_last(a)->index : INT_MAX;
    if(!get_bit(next,bit))
    {
        if(!get_bit(last,bit))
            return(next>last)+2;//Los dos son validos, si es el ultimo menor devuelve 3 
        return 2;//Siguiente valor (2)
    }
    return 0; //Ninguno es valido, rotar

}
