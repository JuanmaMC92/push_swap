/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:43:04 by natferna          #+#    #+#             */
/*   Updated: 2025/01/28 20:43:04 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int mean_index(t_stack *stack)
{
    int sum;
    int count;
    t_node *current;
    current=stack->top;
    sum=0;
    count=0;
    while(current)
    {
        sum+=current->index;
        count++;
        current=current->next;
    }
    return (ft_printf("Mean:%d\n",sum/count),sum/count);
}
void proc_best_friend(t_stack *a,t_stack *b,t_log *log)
{
    int mean;
    int nxt;
    while(a->size>5)
    {
        mean=mean_index(a);
        if(a->top->index<mean)
        {
            pb(a,b,log);
        }
        else
            ra(a,b,log);

    }
    sort_five(a,b,log);
    print_stacks(a,b);
    while(b->size>0)
    {
        nxt=next_index(a,b);
        ft_printf("Next index:%d\n",nxt);
        exec_best(a,b,log,nxt);
    }
    
}
void exec_best(t_stack *a,t_stack *b,t_log *log,int index)
{
    int pos; //position of best element in b
    int friend;
    int f_pos;
    pos=find_position(b,index);
    friend=nearest_index(a,index);
    f_pos=find_position(a,friend);
    
    while((pos+f_pos)>0)
        {
            
            next_rotation(a,b,log,f_pos,pos);
            pos=find_position(b,index);
            f_pos=find_position(a,friend);
            ft_printf("A: %d(%d) - B: %d(%d)\n",friend,f_pos,index,pos);
        }
    pa(a,b,log);
    ft_printf("Node %d moved\n",index);
    print_stacks(a,b);
}
void next_rotation(t_stack *a,t_stack *b,t_log *log,int pos_a,int pos_b)
{
    int dir_a;
    int dir_b;
    
    dir_a=0;
    if(pos_a)
        dir_a=pos_a>moves_to_top(a,pos_a)?-1:1;
    dir_b=0;
    if(pos_b)
        dir_b=pos_b>moves_to_top(b,pos_b)?-1:1;
    if(dir_a==dir_b)
    {
        if(dir_a>0)
            rr(a,b,log);
        else
            rrr(a,b,log);
        return;
    }
    if(dir_a>0)
        ra(a,b,log);
    else if(dir_a<0)
        rra(a,b,log);
    if(dir_b>0)
        rb(a,b,log);
    else if(dir_b<0)
        rrb(a,b,log);
}
int next_index(t_stack *a,t_stack *b)
{
    int friend;
    int moves;
    int optimum;
    int dist;
    int loc;
    int ops;
    t_node *current;
    current=b->top;
    dist=(a->size+b->size)/2;//Max moves
    optimum=current->index;
    while(current)
    {
        moves=0;
        loc=find_position(b,current->index);
        ops=moves_to_top(b,loc);
        moves+=ops;
        friend=nearest_index(a,current->index);
        ft_printf("B(%d) %d >>%d -",loc,current->index,ops);
        loc=find_position(a,friend);
        ops=moves_to_top(a,loc);
        moves+=ops;
        ft_printf("A (%d) %d >>%d ",loc,friend,ops);
        ft_printf("-> %d moves\n",moves);
        if(moves<dist && current->index>optimum)
            {
                optimum=current->index;
                dist=moves;
                ft_printf("Optimum B:%d <<%d>> A:%d\n",optimum,dist,friend);
            }
        current=current->next;
    }
    return optimum;
}
int nearest_index(t_stack *stack,int index)
{
    int delta;
    int diff;
    int nxt;
    int target;
    t_node *current;

    current=stack->top;
    target=max_index(stack);
    delta=stack->size/2;
    while(current)
    {   
        nxt=current->index;
        diff=nxt>index?nxt-index:index-nxt;
        //ft_printf("Index<%d> -%d- <%d>\n",index,diff,nxt);
        if(diff>0 && diff<delta)
        {
            delta=diff;
            target=nxt;
            ft_printf("Index<%d>-%d-<%d>\n",index,diff,target);
        }
            
        current=current->next;
    }
    return target;
}
int find_position(t_stack *stack,int index)
{
    t_node *current;
    int pos;
    current=stack->top;
    pos=0;
    while(current)
    {
        if(current->index==index)
            break;
        pos++;
        current=current->next;
    }
    return pos;
}
int moves_to_top(t_stack *stack,int pos)
{
    if(pos>(stack->size)/2)
        return ((stack->size) -pos);
    else
        return pos;
}
///
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
        //ft_printf("A:%d (%d) - B: %d (%d)\n",link,rem_a,target,rem_b);
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

int near_high(t_stack *stack,int target)
{
    int near;
    int diff;
    int index;
    t_node *current;
    current=stack->top;
    near=max_index(stack);
    while (current)
    {
        index=current->index;
        diff=index-target;
        if(diff>0 && near>index)
            near=index; 
        current=current->next;
    }
    return near;
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
int locate(t_stack *stack,int index)
{
    t_node *current;
    int pos;
    current=stack->top;
    pos=0;
    while(current)
    {
        if(current->index==index)
            break;
        pos++;
        current=current->next;
    }
    return pos;
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
