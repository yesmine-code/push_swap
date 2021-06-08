#ifndef PUSH_SWAP_H
#   define PUSH_SWAP_H


#   include <stdio.h>
#   include <stdlib.h>
#   include <unistd.h>
#   include "../libft/libft.h"

typedef struct  s_element
{
    int value;
    struct s_element *back;
    struct s_element *next;
}               t_element;

void display_list(t_element *elem);
void	ft_add_element(t_element **elem, int new);
int     stack_swap(t_element *elem);
void	ft_elemdel(t_element **elem);
int     ft_elem_size(t_element *elem);
t_element   *ft_elem_get_by_id(t_element *elem, int id);
int     stack_push(t_element **el1, t_element **el2);
void	ft_elemadd_front(t_element **elem, int new);
int     shift_up(t_element **elem);
int     shift_down(t_element **elem);
int     check_if_int(char *arg);
void    ft_error();
int     check_if_doublon(t_element *elem);
int     find_min(t_element *elem);
void    move_min_up(t_element **elem, int pos);
int     is_sorted(t_element *elem);
void    sort_list(t_element **list_a, t_element **list_b);




#endif