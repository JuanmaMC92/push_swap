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
    int index;
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
t_node *get_second_last(t_stack *stack);
t_node *get_last(t_stack *stack);  
void    free_stack(t_stack *stack); 
void    push(t_stack *stack, int value, int index); 
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
int intake (int argc, char **args, t_stack *stack);
int stack_transfer(char **args, t_stack *stack);
// Sorting
int is_sorted(t_stack *stack); 
void sort_stack(t_stack *a, t_stack *b,t_log *log);
void stack_sort(t_stack *a, t_stack *b,t_log *log);
void sort_three(t_stack *a,t_stack *b,t_log *log);
void sort_five(t_stack *a, t_stack *b, t_log *log);
int *stack2array(t_stack *stack);
void quicksort(int *array, int size);
int partition(int *array, int size);
void map_stack(t_stack *stack);
int max_index(t_stack *stack);
//Bits
int get_bit(int number, int position);
int get_max_bits(t_stack *stack);
int bit_count(int number);
int stackrem(t_stack *stack,int position, int bit);
//Optimization
void radix_sort(t_stack *a,t_stack *b,t_log *log);
void proc_radix(t_stack *a,t_stack*b,t_log *log);
void radix_btoa(t_stack *a,t_stack *b,t_log *log,int bit,int max_bits);
int restore_rot(int ra_count,int ra_rem);
int best_rotation(t_stack *stack,int position, int bit,int higher);
int prepare_next(t_stack *stack,int ascending);

//A-to-B
void atob(t_stack *a , t_stack *b, t_log *log,int bit);
void btoa(t_stack *a , t_stack *b, t_log *log);
int prep_atob(t_stack *a , t_stack *b, t_log *log,int bit);
int best_atob(t_stack *a ,int bit);
void push_atob(t_stack *a , t_stack *b, t_log *log,int bit);
void codestop();


/*
// Funciones de ordenamiento
void    sort_small(t_stack *a, t_stack *b); // Ordenar para menos de 5 elementos
void    sort_large(t_stack *a, t_stack *b); // Ordenar para muchos elementos
*/

#endif
