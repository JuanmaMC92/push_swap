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
void proc_btoa(t_stacksys *stacks)
{
    int link;
    int nxt;
    while(stacks->a->size>5)
    {
        link=mean_index(stacks->a);   
        nxt=stacks->a->top->index;
        if(nxt<link)
            pb(stacks->a,stacks->b,stacks->log);
        else
            ra(stacks->a,stacks->b,stacks->log);
    }
    sort_five(stacks->a,stacks->b,stacks->log);
    while(stacks->b->size>0)
    {
        nxt=nxt_btoa(stacks);
        link=near_high(stacks->a,nxt);
        exec_btoa(stacks,nxt,link);
    }
    while (stacks->a->top->index!=0)
    {
        if(moves2top(stacks->a,0)>0)
            ra(stacks->a,stacks->b,stacks->log);
        else
            rra(stacks->a,stacks->b,stacks->log);
    }
}
void exec_btoa(t_stacksys *stacks,int target,int link)
{
    int rem_a;
    int rem_b;
    int sync;

    while(moves2top(stacks->a,link)!=0 || moves2top(stacks->b,target)!=0)
    {
        
        rem_a=moves2top(stacks->a,link);
        rem_b=moves2top(stacks->b,target);
        sync=((rem_a>0 && rem_b>0) || (rem_a<0 && rem_b<0));

        if(sync)
            sync_rotate(stacks,rem_a);
        else
            btoa_step(stacks,rem_a,rem_b);
    }
    pa(stacks->a,stacks->b,stacks->log);

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
int nxt_btoa(t_stacksys *stacks)
{
    int nxt;
    int link;
    int cost;
    int delta;
    stacks->head=stacks->b->top;
    nxt=stacks->head->index;
    cost=(stacks->a->size+stacks->b->size)/2;
    while(stacks->head)
    {
        link=near_high(stacks->a,stacks->head->index);
        delta=btoa_ops(stacks->a,stacks->b,link,stacks->head->index);
        if(delta<cost)
        {
            cost=delta;
            nxt=stacks->head->index;
        }
        stacks->head=stacks->head->next;
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
