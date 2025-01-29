/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:28:16 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 21:28:16 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int main(int argc, char **args)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_log *log;
    log=init_log();
    
    stack_a=create_stack();
    if(!intake(argc,args,stack_a))
    {
        free_stack(stack_a);
        clean_log(log);
        write(2, "Error\n", 6);
        return 1;
    }
    map_stack(stack_a);
    if(!is_sorted(stack_a))
    {
        stack_b=create_stack();
        sort_stack(stack_a, stack_b,log);
        free_stack(stack_b);

    }
    free_stack(stack_a);
    clean_log(log);
    return 0;
}