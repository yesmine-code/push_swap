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
int     find_min_max(t_element *elem, int choice);
void    move_min_max_up(t_element **elem, int pos, int choice);
int     is_sorted(t_element *elem, int choice);
void    sort_list(t_element **list_a, t_element **list_b);
void    sort_five(t_element **list_a, t_element **list_b);
void    sort_three(t_element **list_a);
void    move_lists_up(t_element **elem1, int pos1, t_element **elem2, int pos2);
int     wich_chunk(int c, int min, int max);
int     get_chunk_num(int min, int max);
int     find_max2(t_element *elem);
void sort_three_reverse(t_element **list_b);











#endif