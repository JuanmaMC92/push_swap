#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>     
# include <stdlib.h>    
# include <unistd.h>    
# include <limits.h>
# include "../libft/libft.h" 


typedef struct s_node {
    int value;                 
    struct s_node *next;       
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

typedef struct s_stack {
    t_node *top;               
    int size;                  
} t_stack;


void    sa(t_stack *a, t_stack *b,t_log *log);        
void    sb(t_stack *a, t_stack *b,t_log *log);        
void    ss(t_stack *a, t_stack *b,t_log *log); 
void    pa(t_stack *a, t_stack *b,t_log *log); 
void    pb(t_stack *a, t_stack *b,t_log *log); 
void    ra(t_stack *a, t_stack *b,t_log *log);        
void    rb(t_stack *a, t_stack *b,t_log *log);        
void    rr(t_stack *a, t_stack *b,t_log *log); 
void    rra(t_stack *a, t_stack *b,t_log *log);       
void    rrb(t_stack *a, t_stack *b,t_log *log);       
void    rrr(t_stack *a, t_stack *b,t_log *log); 


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
int is_duplicate(t_stack *stack, int num);
int is_integer(char *str);
t_log *init_log();
void clean_log(t_log *log);
void add_step(t_log *log, char *step);
void print_log(t_log *log);
int intake (int argc, char **args, t_stack *stack);
int stack_transfer(char **args, t_stack *stack);

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
int min_index(t_stack *stack);
int mean_index(t_stack *stack);
void proc_btoa(t_stack *a, t_stack *b, t_log *log);
void exec_btoa(t_stack *a,t_stack *b,t_log *log,int target,int link);
int near_high(t_stack *stack,int target);
int moves2top(t_stack *stack,int target);
int locate(t_stack *stack,int index);
int nxt_btoa(t_stack *a,t_stack *b);
int btoa_ops(t_stack *a,t_stack *b,int link,int target);


#endif
