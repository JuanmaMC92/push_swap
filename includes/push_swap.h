#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>     // Para funciones de depuración (printf, etc.), si es necesario
# include <stdlib.h>    // Para malloc, free, exit
# include <unistd.h>    // Para write
# include <stdbool.h>   // Para valores booleanos (true/false)
# include <limits.h>    // Para valores INT_MIN y INT_MAX

// Macros útiles
# define SUCCESS 0
# define ERROR 1

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

// Funciones principales
void    push_swap(t_stack *stack_a);

// Operaciones de pila
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
/*
// Funciones de ordenamiento
void    sort_small(t_stack *a, t_stack *b); // Ordenar para menos de 5 elementos
void    sort_large(t_stack *a, t_stack *b); // Ordenar para muchos elementos
*/
// Utilidades
t_stack *create_stack(void);   // Crear una nueva pila
void    free_stack(t_stack *stack); // Liberar memoria de una pila
void    push(t_stack *stack, int value); // Añadir un elemento a la pila
int     pop(t_stack *stack);   // Sacar un elemento de la pila
void    print_stack(t_stack *stack);
//bool    is_sorted(t_stack *stack); // Verificar si una pila está ordenada

/*
// Validación de entrada
bool    validate_args(int argc, char **argv); // Validar argumentos
bool    check_duplicates(t_stack *stack);    // Verificar duplicados en la pila
bool    is_integer(const char *str);         // Verificar si una cadena es un entero
*/
#endif
