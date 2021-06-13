#include "include/push_swap.h"

t_element   *ft_elem_get_by_id(t_element *elem, int id)
{
    t_element *el;
    int i;

    i = 0;
    if(elem == NULL || id < 0 || id >= ft_elem_size(elem))
        return NULL;
    el = elem;
    while(i < id)
    {
        el = el->next;
        i++;
    }
    return el;
}

int ft_elem_size(t_element *elem)
{
    t_element *el;
    int i;

    if(elem == NULL)
        return 0;
    i = 0;
    el = elem;
    while(el->next != NULL)
    {
        i++;
        el = el->next;
    }
    return i + 1;
}

t_element	*ft_elemlast(t_element *elem)
{
	if (elem == NULL || elem->next == NULL)
		return (elem);
	return (ft_elemlast(elem->next));
}

void	ft_add_element(t_element **elem, int new)
{
    t_element *last;
    t_element *new_elem;

    new_elem = malloc(sizeof(t_element));
    if(new_elem == NULL)
        return;
    new_elem->value = new;
    new_elem->next = NULL;
	if (elem == NULL)
		return ;
	if (*elem == NULL)
		*elem = new_elem;
	else
    {
		last = ft_elemlast(*elem);
        last->next = new_elem;
        new_elem->back = last;
    }
}

void	ft_elemadd_front(t_element **elem, int new)
{
    t_element   *first_elem;
    t_element   *new_elem;

    if (!elem)
        return;
    new_elem = malloc(sizeof(t_element));
	if (!new_elem)
		return ;
    new_elem->value = new;
    first_elem = *elem;
	new_elem->next = *elem;
    if (*elem != NULL)
	    first_elem->back = new_elem;
    *elem = new_elem;
}

void	ft_elemdel(t_element **elem)
{
    t_element   *el1;
    t_element   *el2;

    if(elem == NULL || *elem == NULL)
        return;
    if((*elem)->next == NULL)
    {
        free(*elem);
        *elem = NULL;
        return;
    }
    el1 = *elem;
    el2 = (*elem)->next;
    *elem = el2;
    free(el1);
    el2->back = NULL;
}

void display_list(t_element *elem)
{
    if(elem != NULL)
    {
        printf("%d\n", elem->value);
        display_list(elem->next);
    }

}
