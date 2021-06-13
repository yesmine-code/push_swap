#include "include/push_swap.h"

int	stack_swap(t_element *elem)
{
	int			tmp;
	t_element	*el1;
	t_element	*el2;

	if (elem->next == NULL)
		return (0);
	el1 = elem;
	el2 = elem->next;
	tmp = el2->value;
	el2->value = el1->value;
	el1->value = tmp;
	return (1);
}

int	stack_push(t_element **el1, t_element **el2)
{
	int	tmp;

	if (el1 == NULL || *el1 == NULL || el2 == NULL)
		return (0);
	tmp = (*el1)->value;
	ft_elemdel(el1);
	ft_elemadd_front(el2, tmp);
	return (1);
}

int	shift_up(t_element **elem)
{
	int			size;
	t_element	*el1;
	t_element	*last1;
	t_element	*last2;

	if (elem == NULL || *elem == NULL)
		return (0);
	size = ft_elem_size(*elem);
	if (size == 1)
		return (1);
	if (size == 2)
		return (stack_swap(*elem));
	el1 = *elem;
	last1 = ft_elem_get_by_id(*elem, size - 1);
	last2 = last1->back;
	*elem = last1;
	last1->back = NULL;
	last1->next = el1;
	last2->next = NULL;
	el1->back = last1;
	return (1);
}

int	shift_down(t_element **elem)
{
	int			size;
	t_element	*el1;
	t_element	*last;
	t_element	*el2;

	if (elem == NULL || *elem == NULL)
		return (0);
	size = ft_elem_size(*elem);
	if (size == 1)
		return (1);
	if (size == 2)
		return (stack_swap(*elem));
	el1 = *elem;
	last = ft_elem_get_by_id(*elem, size - 1);
	el2 = el1->next;
	*elem = el2;
	el1->back = last;
	el1->next = NULL;
	el2->back = NULL;
	last->next = el1;
	return (1);
}
