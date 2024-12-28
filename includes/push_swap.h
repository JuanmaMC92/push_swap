#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>     // Para funciones de depuración (printf, etc.), si es necesario
# include <stdlib.h>    // Para malloc, free, exit
# include <unistd.h>    // Para write
# include <stdbool.h>   // Para valores booleanos (true/false)
# include <limits.h>    // Para valores INT_MIN y INT_MAX
# include "../libft/libft.h" 

// Estructura para los nodos de la pila
typedef struct s_node {
    int value;                 // Valor del nodo
    struct s_node *next;       // Puntero al siguiente nodo
} t_node;

// Estructura para la pila
typedef struct s_stack {
    t_node *top;               // Puntero al elemento superior de la pila
    int size;                  // Tamaño actual de la pila
} t_stack;

// Operatios
void    sa(t_stack *a);        // Swap para la pila A
void    sb(t_stack *b);        // Swap para la pila B
void    ss(t_stack *a, t_stack *b); // Swap simultáneo
void    pa(t_stack *a, t_stack *b); // Push desde B a A
void    pb(t_stack *a, t_stack *b); // Push desde A a B
void    ra(t_stack *a);        // Rotate A
void    rb(t_stack *b);        // Rotate B
void    rr(t_stack *a, t_stack *b); // Rotate simultáneo
void    rra(t_stack *a);       // Reverse Rotate A
void    rrb(t_stack *b);       // Reverse Rotate B
void    rrr(t_stack *a, t_stack *b); // Reverse Rotate simultáneo

// Utils
t_stack *create_stack(void);  
void    free_stack(t_stack *stack); 
void    push(t_stack *stack, int value); 
int     pop(t_stack *stack);   
void    print_stack(t_stack *stack);
int parse_arguments(int argc, char *argv[], t_stack **stack);
int is_duplicate(t_stack *stack, int num);
int is_integer(char *str);
// Sorting
int is_sorted(t_stack *stack); 
void sort_stack(t_stack **stack_a, t_stack **stack_b);
/*
// Funciones de ordenamiento
void    sort_small(t_stack *a, t_stack *b); // Ordenar para menos de 5 elementos
void    sort_large(t_stack *a, t_stack *b); // Ordenar para muchos elementos
*/

#endif
