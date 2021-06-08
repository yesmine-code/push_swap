#include "include/push_swap.h"

int find_min(t_element *elem)
{
    int min;
    int j;
    int size;
    int pos;
    t_element *list;

    j = 1;
    pos = 0;
    list = elem;
    min = list->value;
    size = ft_elem_size(elem);
    while(j < size && list->next != NULL)
    {
        list = list->next;
        if(list->value < min)
        {
            min = list->value;
            pos = j;
        }
        j++;
    }
    return pos;
}

void move_min_up(t_element **elem, int pos)
{
    int i;
    int size;

    i = pos;
    size = ft_elem_size(*elem);
    if(pos == 1)
    {
        stack_swap(*elem);
        ft_putstr_fd("sa\n", 1);
    }
    else if(pos < size / 2)
    {
        while(i > 0)
        {
            shift_down(elem);
            ft_putstr_fd("ra\n", 1);
            i--;
        }
    }
    else
    {
         while(i < size)
        {
            shift_up(elem);
            ft_putstr_fd("rra\n", 1);
            i++;
        }
    }
}

int is_sorted(t_element *elem)
{
    int i;
    int size;
    t_element *el;

    el = elem;
    size = ft_elem_size(elem);
    i = 0;
    while(i < size - 1 && el->next != NULL)
    {
        if (el->value > el->next->value)
            return 0;
        el = el->next;
        i++;
    }
    return 1;
}