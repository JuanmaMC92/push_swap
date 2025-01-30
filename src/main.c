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
    t_stacksys *stacks;
    stacks=setup_stacks(2);
    if(!intake(argc,args,stacks->a))
    {
        clean_stacks(stacks);
        write(2, "Error\n", 6);
        return 1;
    }
    map_stack(stacks->a);
    if(!is_sorted(stacks->a))
    {
        sort_stack(stacks);

    }
    clean_stacks(stacks);
    return 0;
}