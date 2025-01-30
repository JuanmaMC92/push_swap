/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:52:34 by natferna          #+#    #+#             */
/*   Updated: 2025/01/30 18:52:34 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacksys *setup_stacks(int mode)
{
    t_stacksys *sys= malloc(sizeof(t_stacksys));
    if (!sys){
        ft_printf("Error: Could not allocate memory for stacks\n");
        return NULL; 
    }
    sys->a=NULL;
    sys->b=NULL;
    sys->log=NULL;
    sys->head=NULL;
    if(mode==1)
        sys->log=init_log();
    else if(mode==2)
        {
            sys->a=create_stack();
            sys->b=create_stack();
            sys->log=init_log();
            sys->head=malloc(sizeof(t_node));
        }

    return sys;
}
void clean_stacks(t_stacksys *sys)
{
    if(!sys->a)
        free_stack(sys->a);
    if(!sys->b)
        free_stack(sys->b);
    if(!sys->log)
        clean_log(sys->log);
    if(!sys->head)
        free(sys->head);
    sys->a=NULL;
    sys->b=NULL;
    sys->log=NULL;
    sys->head=NULL;
    free(sys);
}
