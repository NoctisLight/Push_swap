#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct nodea{
    int val;
    struct nodea *next;
} stack_a;

typedef struct nodeb{
    int val;
    struct node *next;
} stack_b;

typedef struct heada{
    int head;
} head_a;

typedef struct headb{
    int head;
} head_b;

int	ft_printf(const char *format, ...);
stack_a *ft_atoi(stack_a *first, stack_a *head, const char *string);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
stack_a *sa(stack_a *head_a, stack_a *first_a);
int list_len(stack_a *first_a);
#endif