#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct nodea{
    int val;
    struct nodea *next;
    struct nodea *prev; // pointer to the prev node
} stack_a;

typedef struct nodeb{
    int val;
    struct nodeb *next;
    struct nodeb *prev; // pointer to the prev node
} stack_b;

typedef struct s_data{
    int max;
    int min;
    int cost;
} t_data;


int	ft_printf(const char *format, ...);
stack_a *ft_atoi(stack_a *first, stack_a *head, const char *string, t_data **data);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void sa(stack_a **head_a, stack_a *first_a);
void sb(stack_b **head_b, stack_b *first_b);
void ss(stack_a **head_a, stack_a *first_a, stack_b **head_b, stack_b *first_b);
int list_len_a(stack_a *first_a);
int list_len_b(stack_b *first_b);
void pa(stack_a **head_a, stack_b **head_b, stack_b *first_b);
void pb(stack_a **head_a, stack_b **head_b, stack_a *first_a);
void ra(stack_a **head_a, stack_a **first_a);
void rb(stack_b **head_b, stack_b **first_b);
void rr(stack_a **head_a, stack_a **first_a, stack_b **head_b, stack_b **first_b);
void rra(stack_a **head_a, stack_a **first_a);
void less_than_3(stack_a **head_a);
#endif