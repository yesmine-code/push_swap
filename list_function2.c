#include "include/push_swap.h"

void	ft_elemadd_front(t_element **elem, int new)
{
	t_element	*first_elem;
	t_element	*new_elem;

	if (!elem)
		return ;
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
	t_element	*el1;
	t_element	*el2;

	if (elem == NULL || *elem == NULL)
		return ;
	if ((*elem)->next == NULL)
	{
		free(*elem);
		*elem = NULL;
		return ;
	}
	el1 = *elem;
	el2 = (*elem)->next;
	*elem = el2;
	free(el1);
	el2->back = NULL;
}

void	display_list(t_element *elem)
{
	if (elem != NULL)
	{
		printf("%d\n", elem->value);
		display_list(elem->next);
	}
}

void	ft_free(t_element *list_a, t_element *list_b)
{
	while (list_a->next != NULL)
		ft_elemdel(&list_a);
	free(list_a);
	if (list_b != NULL)
		free(list_b);
}
