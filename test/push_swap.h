#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/* utils */
int     ft_atoi(const char *str);
void    ft_putstr(char *s);
void    ft_error(void);
int     is_sorted(int *tab, int size);

/* stack ops */
void    sa(int *a, int size);
void    ra(int *a, int size);
void    rra(int *a, int size);
void    pb(int *a, int *b, int *size_a, int *size_b);
void    pa(int *a, int *b, int *size_a, int *size_b);
void    rb(int *b, int size);
void    rrb(int *b, int size);

/* sorting */
void    push_swap_sort(int *a, int *b, int *size_a, int *size_b);
void    sort_small(int *a, int *b, int *size_a, int *size_b);

/* indexing */
void    index_stack(int *a, int size);

#endif
