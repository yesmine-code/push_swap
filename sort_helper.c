#include "include/push_swap.h"

int find_min_max(t_element *elem, int choice)
{
    int min_max;
    int j;
    int size;
    int pos;
    t_element *list;

    if(elem == NULL)
        return 0;
    j = 1;
    pos = 0;
    list = elem;
    min_max = list->value;
    size = ft_elem_size(elem);
    while(j < size && list->next != NULL)
    {
        list = list->next;
        if(choice == 0 && list->value < min_max)
        {
            min_max = list->value;
            pos = j;
        }
        else if(choice == 1 && list->value > min_max)
        {
            min_max = list->value;
            pos = j;
        }
        j++;
    }
    return pos;
}

void move_min_max_up(t_element **elem, int pos, int choice, int min, int max)
{
    int i;
    int size;

    i = pos;
    size = ft_elem_size(*elem);
    if( pos == 0)
        return;
    if(pos == 1 && choice == 0)
    {
        if(wich_chunk((*elem)->value, min, max) == wich_chunk((*elem)->next->value, min, max))
        {
            stack_swap(*elem);
            ft_putstr_fd("sa\n", 1);
            return;
        }
    }
    if(pos == 1 && choice == 1)
    {
        if(wich_chunk((*elem)->value, min, max) == wich_chunk((*elem)->next->value, min, max))
        {
            stack_swap(*elem);
            ft_putstr_fd("sb\n", 1);
            return;
        }
    }
    if(pos < size / 2)
    {
        while(i > 0)
        {
            shift_down(elem);
            if (choice == 0)
                ft_putstr_fd("ra\n", 1);
            else
                ft_putstr_fd("rb\n", 1);
            i--;
        }
    }
    else
    {
         while(i < size)
        {
            shift_up(elem);
            if (choice == 0)
                ft_putstr_fd("rra\n", 1);
            else
                ft_putstr_fd("rrb\n", 1);
            i++;
        }
    }
}


void move_lists_up(t_element **elem1, int pos1, t_element **elem2, int pos2)
{
    int i;
    int j;
    int size1;
    int size2;


    i = pos1;
    size1 = ft_elem_size(*elem1);
    j = pos2;
    size2 = ft_elem_size(*elem2);
   
   if(pos1 < size1 / 2 && pos2 < size2 / 2)
   {
        while(i > 0 && j > 0)
        {
            shift_down(elem1);
            shift_down(elem2);
            ft_putstr_fd("rr\n", 1);
            i--;
            j--;
        }
        while (i > 0)
        {
            shift_down(elem1);
            ft_putstr_fd("ra\n", 1);
            i--;
        }
        while (j > 0)
        {
            shift_down(elem2);
            ft_putstr_fd("rb\n", 1);
            j--;
        }
   }
   else if (pos1 >= size1 / 2 && pos2 >= size2 / 2)
   {
        while(i < size1 && j < size2)
        {
            shift_up(elem1);
            shift_up(elem2);
            ft_putstr_fd("rrr\n", 1);
            i++;
            j++;
        }
        while (i < size1)
        {
            shift_up(elem1);
            ft_putstr_fd("rra\n", 1);
            i++;
        }
        while (j < size2)
        {
            shift_up(elem2);
            ft_putstr_fd("rrb\n", 1);
            j++;
        }
   }
   else
   {
       move_min_max_up(elem1, pos1, 0, 0, 0);
       move_min_max_up(elem2, pos2, 1, 0, 0);
   }
}

int is_sorted(t_element *elem, int choice)
{
    int i;
    int size;
    t_element *el;

    el = elem;
    size = ft_elem_size(elem);
    i = 0;
    while(i < size - 1 && el->next != NULL)
    {
        if (choice == 0 && el->value > el->next->value)
            return 0;
        else if (choice == 1 && el->value < el->next->value)
            return 0;
        el = el->next;
        i++;
    }
    return 1;
}