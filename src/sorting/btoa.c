/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:28:29 by natferna          #+#    #+#             */
/*   Updated: 2025/01/29 23:28:29 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void proc_btoa(t_stack *a,t_stack *b,t_log *log)
{
    int link;
    int nxt;
    while(a->size>5)
    {
        link=mean_index(a);   
        nxt=a->top->index;
        if(nxt<link)
            pb(a,b,log);
        else
            ra(a,b,log);
    }
    sort_five(a,b,log);
    while(b->size>0)
    {
        nxt=nxt_btoa(a,b);
        link=near_high(a,nxt);
        exec_btoa(a,b,log,nxt,link);
    }
    while (a->top->index!=0)
    {
        if(moves2top(a,0)>0)
            ra(a,b,log);
        else
            rra(a,b,log);
    }
}
void exec_btoa(t_stack *a,t_stack *b,t_log *log,int target,int link)
{
    int rem_a;
    int rem_b;
    int sync;

    while(moves2top(a,link)!=0 || moves2top(b,target)!=0)
    {
        
        rem_a=moves2top(a,link);
        rem_b=moves2top(b,target);
        sync=((rem_a>0 && rem_b>0) || (rem_a<0 && rem_b<0));
        if(sync)
        {
            sync=rem_a>0?(rr(a,b,log),0):(rrr(a,b,log),1);
            continue;
        }
        if(rem_a)
            rem_a=rem_a>0?(ra(a,b,log),0):(rra(a,b,log),1);
        if(rem_b)
            rem_b=rem_b>0?(rb(a,b,log),0):(rrb(a,b,log),1);
    }
    pa(a,b,log);
}


int moves2top(t_stack *stack,int target)
{
    int pos;
    int dist;
    int dir;
    pos=locate(stack,target);
    dist=pos;
    dir=pos>stack->size/2?-1:1;
    if(dir<0)
        dist=pos-stack->size;
    return dist;
}
int nxt_btoa(t_stack *a,t_stack *b)
{
    t_node *current;
    int nxt;
    int link;
    int cost;
    int delta;
    current=b->top;
    nxt=current->index;
    cost=(a->size+b->size)/2;
    while(current)
    {
        link=near_high(a,current->index);
        delta=btoa_ops(a,b,link,current->index);
        if(delta<cost)
        {
            cost=delta;
            nxt=current->index;
        }
        current=current->next;
    }
    return nxt;
}
int btoa_ops(t_stack *a,t_stack *b,int link,int target)
{
    int ramp_a;
    int ramp_b;
    int cost;
    ramp_a=moves2top(a,link);
    ramp_b=moves2top(b,target);
    if(ramp_b>=0)
    {
        if(ramp_a>0)
            cost=ramp_a>ramp_b?ramp_a:ramp_b;
        else
            cost = ramp_b - ramp_a;
    }
    else
    {
        if(ramp_a<0)
            cost=ramp_a<ramp_b?-ramp_a:-ramp_b;
        else
            cost = ramp_a - ramp_b;
    }
    return cost;
}
