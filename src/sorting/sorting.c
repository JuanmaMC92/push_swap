/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:19:28 by natferna          #+#    #+#             */
/*   Updated: 2024/12/31 12:19:28 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"
#include <limits.h>

int has_values_below_median(t_stack *a, int median)
{
    t_node *current;
    current = a->top;
    while (current) {
        if (current->value < median) {
            return 1; // Hay valores menores a la mediana
        }
        current = current->next;
    }
    return 0; // No hay valores menores a la mediana
}
int find_candidate(t_stack *a, int median)
{
    t_node *current;
    int candidate;
    current = a->top;
    candidate = INT_MIN;
    
    while (current) {
        if (current->value < median && current->value > candidate) {
            candidate = current->value; // Actualiza el candidato
        }
        current = current->next;
    }
    return candidate;
}

void move_to_top(t_stack *a,t_stack *b, int value,t_log *log)
{
    int index ;
    t_node *current;
    
    current = a->top;
    index = 0;
    while (current && current->value != value) {
        index++;
        current = current->next;
    }

    if (index <= a->size / 2) {
        while (index) 
        {
            ra(a,b,log);
            index--;
        }
    } else {
        index = a->size - index;
        while (index) 
        {
            rra(a,b,log);
            index--;
        }
    }
}

void stack_sort(t_stack *a, t_stack *b,t_log *log)
{
    int median;
    int candidate;
    median=INT_MIN;
    
    print_stacks(a,b);
    
    while (a->size > 3) {
        median = find_median(a);
        while (has_values_below_median(a, median)) 
        {
            candidate = find_candidate(a, median);
            send2temp(a,b,log,candidate);
        }
        send2temp(a,b,log,median);
    }


    sort_three(a,b,log); // Ordena los últimos 4 valores en a
    while (b->size > 0) {
        sort_temp(a,b,log);
        pa(a, b,log); // Devuelve los valores desde b a a
    }
}
void send2temp(t_stack *a,t_stack *b,t_log *log,int value)
{
    move_to_top(a,b, value,log); // Usa ra o rra según sea necesario
    pb(a, b,log);                 // Mueve el candidato a b
    sort_temp(a,b,log);
}
void sort_temp(t_stack *a,t_stack *b,t_log *log)
{
    t_node *last;
    if (b->size > 1)
    {   
        last=b->top;
        while(last->next)
            last=last->next;
        if (b->top->value< last->value)
            rb(a,b,log);
        if(b->top->value < b->top->next->value)
            sb(a,b,log); // Asegura el orden en b}
    }
}
