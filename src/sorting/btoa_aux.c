/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:17:21 by natferna          #+#    #+#             */
/*   Updated: 2025/01/30 19:17:21 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sync_rotate(t_stacksys *stacks,int dir)
{
    if(dir>0)
        rr(stacks->a,stacks->b,stacks->log);
    else
        rrr(stacks->a,stacks->b,stacks->log);
}
void btoa_step(t_stacksys *stacks,int rem_a,int rem_b)
{
    
    if(rem_a>0)
        ra(stacks->a,stacks->b,stacks->log);
    else if(rem_a<0)
        rra(stacks->a,stacks->b,stacks->log);


    if(rem_b>0)
        rb(stacks->a,stacks->b,stacks->log);
    else if(rem_b<0)
        rrb(stacks->a,stacks->b,stacks->log);
    
}
