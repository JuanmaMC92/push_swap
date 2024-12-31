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

typedef struct s_step {
    char *step;                 
    struct s_step *next;       
} t_step;

typedef struct s_log {
    int count;                 
    t_step *head;       
} t_log;
// Estructura para la pila
typedef struct s_stack {
    t_node *top;               // Puntero al elemento superior de la pila
    int size;                  // Tamaño actual de la pila
} t_stack;

// Operatios
void    sa(t_stack *a, t_stack *b,t_log *log);        // Swap para la pila A
void    sb(t_stack *a, t_stack *b,t_log *log);        // Swap para la pila B
void    ss(t_stack *a, t_stack *b,t_log *log); // Swap simultáneo
void    pa(t_stack *a, t_stack *b,t_log *log); // Push desde B a A
void    pb(t_stack *a, t_stack *b,t_log *log); // Push desde A a B
void    ra(t_stack *a, t_stack *b,t_log *log);        // Rotate A
void    rb(t_stack *a, t_stack *b,t_log *log);        // Rotate B
void    rr(t_stack *a, t_stack *b,t_log *log); // Rotate simultáneo
void    rra(t_stack *a, t_stack *b,t_log *log);       // Reverse Rotate A
void    rrb(t_stack *a, t_stack *b,t_log *log);       // Reverse Rotate B
void    rrr(t_stack *a, t_stack *b,t_log *log); // Reverse Rotate simultáneo

// Utils
t_stack *create_stack(void);  
void    free_stack(t_stack *stack); 
void    push(t_stack *stack, int value); 
int     pop(t_stack *stack);
void    swap(t_stack *stack);
void    rotate(t_stack *stack);   
void    reverse(t_stack *stack);
void    print_stack(t_stack *stack);
void    print_stacks(t_stack *a, t_stack *b);
int parse_arguments(int argc, char *argv[], t_stack *stack);
int is_duplicate(t_stack *stack, int num);
int is_integer(char *str);
t_log *init_log();
void clean_log(t_log *log);
void add_step(t_log *log, char *step);
void print_log(t_log *log);

// Sorting
int is_sorted(t_stack *stack); 
void sort_stack(t_stack *stack_a, t_stack *stack_b,t_log *log);
void stack_sort(t_stack *a, t_stack *b,t_log *log);
int *stack2array(t_stack *stack);
void quicksort(int *array, int size);
int find_median(t_stack *stack);
void sort_three(t_stack *a,t_stack *b,t_log *log);
void move_to_top(t_stack *a,t_stack *b, int value,t_log *log);
int find_candidate(t_stack *a, int median) ;
int has_values_below_median(t_stack *a, int median);
void sort_temp(t_stack *a,t_stack *b,t_log *log);
void send2temp(t_stack *a,t_stack *b,t_log *log,int value);

/*
// Funciones de ordenamiento
void    sort_small(t_stack *a, t_stack *b); // Ordenar para menos de 5 elementos
void    sort_large(t_stack *a, t_stack *b); // Ordenar para muchos elementos
*/

#endif
