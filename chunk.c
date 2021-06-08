#include "include/push_swap.h"


void get_min_max(t_element *elem, int *min, int *max)
{
    int j;
    int size;
    t_element *list;

    j = 1;
    list = elem;
    *min = list->value;
    *max = list->value;
    size = ft_elem_size(elem);
    while(j < size && list->next != NULL)
    {
        list = list->next;
        if(list->value < *min)
            *min = list->value;
        else if(list->value > *max)
            *max = list->value;
        j++;
    }
}

int get_chunk_num(int min, int max)
{
    if(max - min <= 100)
        return 5;
    else
        return 11;
}

int wich_chunk(int c, int min, int max)
{
    int i;
    int chunk_num;
   
    i = 1;
    chunk_num = get_chunk_num(min, max);
    while(i <= chunk_num)
    {
        if (c < ((max - min) / chunk_num) * i)
            return i;
        i++;
    }
    return i;
}

void sort_list(t_element **list_a, t_element **list_b)
{
    t_element *last_elem;
    t_element *elem;
    int hold_first;
    int hold_second;
    int min;
    int max;
    int i;
    int chunk;
    int chunk_num;

    chunk = 1;
    i = 0;
    get_min_max(*list_a, &min, &max);
    chunk_num = get_chunk_num(min, max);
    last_elem = *list_a;
    while(last_elem->next != NULL)
            last_elem = last_elem->next;
    while(chunk <= chunk_num)
    {
        hold_first = -1;
        hold_second = -1;
        i = 0;
        elem = *list_a;
        while(i < ft_elem_size(*list_a) / 2)
        {
            if(wich_chunk(elem->value, min, max) == chunk)
            {
                hold_first = i;
                break;
            }
            i++;
            elem = elem->next;
        }
        i = ft_elem_size(*list_a) - 1;
        elem = last_elem;
        while(i >= ft_elem_size(*list_a) / 2)
        {
            if(wich_chunk(elem->value, min, max) == chunk)
            {
                hold_second = i;
                break;
            }
            i--;
            elem = elem->back;
        }
        if(hold_first != -1 && hold_first < ft_elem_size(*list_a) - hold_second)
        {
            move_min_up(list_a, hold_first);
            stack_push(list_a, list_b);
            ft_putstr_fd("pb\n", 1);
        }
        else if(hold_second != -1)
        {
            move_min_up(list_a, hold_second);
            stack_push(list_a, list_b);
            ft_putstr_fd("pb\n", 1);
        }
        else
            chunk++;
    }
}