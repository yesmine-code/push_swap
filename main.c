#include "include/push_swap.h"

void sort_three(t_element **list_a)
{
    int a;
    int b;
    int c;
    t_element *elem;

    elem = (*list_a)->next;
    a = (*list_a)->value;
    b = elem->value;
    c = elem->next->value;

    if(a > b  && a > c && b < c)
    {
        shift_down(list_a);
        ft_putstr_fd("ra\n", 1);
    }
    else if (a < b && a < c && c < b)
    {
        shift_up(list_a);
        ft_putstr_fd("rra\n", 1);
        stack_swap(*list_a);
        ft_putstr_fd("sa\n", 1);
    }
    else if(a < b && c < b && c < a)
    {
        shift_up(list_a);
        ft_putstr_fd("rra\n", 1);
    }
    else if (c > a && c > b && a > b)
    {
        stack_swap(*list_a);
        ft_putstr_fd("sa\n", 1);
    }
    else if ( a > b && b > c && a > c)
    {
        stack_swap(*list_a);
        ft_putstr_fd("sa\n", 1);
        shift_up(list_a);
        ft_putstr_fd("rra\n", 1);
    }
}

void sort_five(t_element **list_a, t_element **list_b)
{
    int pos;
    int i;

    i = 0;
    while(ft_elem_size(*list_a) > 3)
    {
        pos = find_min_max(*list_a, 0);
        move_min_max_up(list_a, pos, 0);
        if(is_sorted(*list_a, 0) == 0)
        {
            stack_push(list_a, list_b);
            ft_putstr_fd("pb\n", 1);
            i++;
        }
        else
            break;
    }
    sort_three(list_a);
    while(i > 0)//ft_elem_size(*list_b) > 0)
    {
        stack_push(list_b, list_a);
        ft_putstr_fd("pa\n", 1);
        i--;
    }
}
void sort_three_reverse(t_element **list_b)
{
    int a;
    int b;
    int c;
    t_element *elem;

    elem = (*list_b)->next;
    a = (*list_b)->value;
    b = elem->value;
    c = elem->next->value;

    if(a > b  && a > c && b < c)
    {
        stack_swap(*list_b);
        ft_putstr_fd("sb\n", 1);
        shift_down(list_b);
        ft_putstr_fd("rb\n", 1);
    }
    else if (a < b && a < c && c < b)
    {
        shift_down(list_b);
        ft_putstr_fd("rb\n", 1);
    }
    else if(a < b && c < b && c < a)
    {
        stack_swap(*list_b);
        ft_putstr_fd("sb\n", 1);
    }
    else if (c > a && c > b && a > b)
    {
       shift_up(list_b);
       ft_putstr_fd("rrb\n", 1);
    }
    else if ( a < b && b < c && a < c)
    {
        stack_swap(*list_b);
        ft_putstr_fd("sb\n", 1);
        shift_up(list_b);
        ft_putstr_fd("rrb\n", 1);
    }
}

int  main(int ac, char **av)
{
    t_element *list_a;
    t_element *list_b;
    t_element *element;
    int i;

    list_a = NULL;
    list_b = NULL;
    if(ac == 1)
        exit(EXIT_SUCCESS);
    i = 0;
    while(i < ac -1)
    {
        if(check_if_int(av[i + 1])== 0)
            ft_error();
        ft_add_element(&list_a, ft_atoi(av[i + 1]));
        i++;
    }
    if(check_if_doublon(list_a) == 0)
    {
        free(list_a);
        ft_error();
    }
    
    if (ac == 3)
    {
        element = list_a->next;
        if(list_a->value > element->value)
            stack_swap(list_a);
        exit(EXIT_SUCCESS);
    }
    if (ac == 4)
    {
       sort_three(&list_a);
       free(list_a);
       exit(EXIT_SUCCESS);
    }
    if (ac <= 6)
    {
        sort_five(&list_a, &list_b);
        free(list_b);
        free(list_a);
        exit(EXIT_SUCCESS);
    }
    else
        sort_list(&list_a, &list_b);
 //  display_list(list_a);
  //printf("\n-------------\n");
   //display_list(list_b);
    free(list_a);
    exit(EXIT_SUCCESS);
}
