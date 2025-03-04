/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:48:25 by natferna          #+#    #+#             */
/*   Updated: 2024/12/27 21:48:25 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int intake(int argc, char **args, t_stack *stack)
{
    int i;
    char **data;

    if (argc==1)
            return(ft_printf("No input\n"),0);
    if (argc==2)
        data=ft_split(args[1],' ');
    else
    {
        data = (char **)malloc((argc - 1) * sizeof(char *));
        i=0;
        while(i<argc-1){
            data[i]=ft_strdup(args[i+1]);
            i++;
        }
        data[argc - 1] = NULL; 
    }       
    return stack_transfer(data,stack);
}

int stack_transfer(char **args, t_stack *stack)
{
    int i;
    int num;
    i=0;
    while(args[i])
    {
        if (!is_integer(args[i]))  
            return 0;
        num = ft_atoi(args[i]);
        
        if (num > INT_MAX || num  < INT_MIN ||is_duplicate(stack, num))  
            return 0;
        push(stack, num,0);  
        i++;
    }
    return 1;
}
int is_integer(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;  
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;  
        i++;
    }
    return 1;  
}

int is_duplicate(t_stack *stack, int num)
{
    t_node *current;

    if (!stack || !stack->top)
        return (0); 
    current = stack->top; 
    while (current)
    {
        if (current->value == num)
            return 1;
        current = current->next;  
    }
    return 0;
}
