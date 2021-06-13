#include "include/push_swap.h"

void	push_elements(t_element **list_a, t_element **list_b, int choice)
{
	int	pos;

	pos = 0;
	while (ft_elem_size(*list_a) > 0)
	{
		pos = find_min_max(*list_a, choice);
		move_min_max_up(list_a, pos, choice);
		stack_push(list_a, list_b);
		if (choice == 0)
			ft_putstr_fd("pb\n", 1);
		else
			ft_putstr_fd("pa\n", 1);
	}
}

void	sort_chunks(t_element **list_a, t_element **list_b, int hold)
{
	int	pos;

	pos = find_min_max(*list_b, 1);
	move_lists_up(list_a, hold, list_b, pos);
	stack_push(list_a, list_b);
	ft_putstr_fd("pb\n", 1);
}

int	find_hold_first(t_element *list_a, int min, int max, int chunk)
{
	int			hold_first;
	int			i;
	t_element	*elem;

	hold_first = -1;
	i = 0;
	elem = list_a;
	while (i < ft_elem_size(list_a) / 2)
	{
		if (wich_chunk(elem->value, min, max) == chunk)
		{
			hold_first = i;
			break ;
		}
		i++;
		elem = elem->next;
	}
	return (hold_first);
}

int	find_hold_second(t_element *list_a, int min, int max, int chunk)
{
	int			i;
	t_element	*last_elem;
	t_element	*elem;
	int			hold_second;

	hold_second = -1;
	i = ft_elem_size(list_a) - 1;
	last_elem = list_a;
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	elem = last_elem;
	while (i >= ft_elem_size(list_a) / 2)
	{
		if (wich_chunk(elem->value, min, max) == chunk)
		{
			hold_second = i;
			break ;
		}
		i--;
		elem = elem->back;
	}
	return (hold_second);
}

void	sort_list(t_element **list_a, t_element **list_b)
{
	int	hold_first;
	int	hold_second;
	int	min;
	int	max;
	int	chunk;

	chunk = 1;
	get_min_max(*list_a, &min, &max);
	while (chunk < get_chunk_num(min, max) && ft_elem_size(*list_a) > 5)
	{
		hold_first = find_hold_first(*list_a, min, max, chunk);
		hold_second = find_hold_second(*list_a, min, max, chunk);
		if (hold_first != -1 && (hold_first < ft_elem_size(*list_a)
				- hold_second || hold_second == -1))
			sort_chunks(list_a, list_b, hold_first);
		else if (hold_second != -1)
			sort_chunks(list_a, list_b, hold_second);
		else
			chunk++;
	}
	push_elements(list_a, list_b, 0);
	push_elements(list_b, list_a, 1);
}
