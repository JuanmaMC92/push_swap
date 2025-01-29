/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:21:53 by natferna          #+#    #+#             */
/*   Updated: 2024/12/28 21:21:53 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || stack->size <= 1) // Si el stack está vacío o tiene un solo elemento
        return 1;

    current = stack->top;
    while (current && current->next)
    {
        if (current->index > current->next->index)
            return (ft_printf("Node:%d(%d) > Next: %d (%d)\n",current->value,current->index,current->next->value,current->next->index),0); // Encontró un desorden, no está ordenado
        current = current->next;
    }
    return 1; // Está completamente ordenado
}
void sort_stack(t_stack *a, t_stack *b,t_log *log)
{
    if(!is_sorted(a) && a->size>1)
        stack_sort(a,b,log);
    print_log(log);
    ft_printf("<<%s>>\n",is_sorted(a)?"Sorted successfully":"Unable to sort");
    print_stack(a);
    ft_printf("|A\n");
}
void stack_sort(t_stack *a, t_stack *b,t_log *log)
{
    ///Main sorting algorithm
    if (a->size==2)
        sa(a,b,log);
    else if (a->size<4)
        sort_three(a,b,log);
    
    else if (a->size<6)
        sort_five(a,b,log);
    
    else
        proc_btoa(a,b,log);
}
void sort_three(t_stack *a,t_stack *b,t_log *log)
{
    int head;
    int next;
    int last;
    

    while(!is_sorted(a))
    {// Options( 1-3-2 : 2-1-3 : 3-2-1 : 2-3-1 : 3-1-2 )
        head=a->top->index;
        next=a->top->next->index;
        last=get_last(a)->index;
        if(head>next)
        {//2-1-3 : 3-2-1 : 3-1-2
            if(head>last)//3-2-1 -> 2-1-3 : 3-1-2 -> 1-2-3 (o)
                ra(a,b,log);
            else//2-1-3 -> 1-2-3 (o)
                sa(a,b,log);
        }
        else//1-3-2 -> 2-1-3 : 2-3-1 -> 1-2-3 (o)
            rra(a,b,log);
    }
}
void sort_five(t_stack *a, t_stack *b, t_log *log)
{
    int i;
    ft_printf("Sort-five Strategy-%d\n",a->size);
    while (a->size > 3) // Mover los dos elementos más pequeños a B
    {
        ft_printf("Top item:%d(%d)\n",a->top->value,a->top->index);
        if (a->top->index ==min_index(a))
            pb(a, b, log); // Push mínimo a stack B
        else
            ra(a, b, log); // Rotate hasta encontrar los mínimos
        //ft_printf("A size-%d\n",a->size);
    }
    sort_three(a, b, log); // Ordenar los tres elementos restantes
    ft_printf("A sorted, return from B\n");
    if(is_sorted(b))
        sb(a, b, log); 
    i=2;
    while(i--)
        pa(a, b, log); // Reinsertar elementos de B
}
