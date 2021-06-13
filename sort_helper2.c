#include"include/push_swap.h"

int	find_min_max(t_element *elem, int choice)
{
	int			min_max;
	int			j;
	int			pos;
	t_element	*list;

	if (elem == NULL)
		return (0);
	j = 1;
	pos = 0;
	list = elem;
	min_max = list->value;
	while (j < ft_elem_size(elem) && list->next != NULL)
	{
		list = list->next;
		if ((choice == 0 && list->value < min_max)
			|| (choice == 1 && list->value > min_max))
		{
			min_max = list->value;
			pos = j;
		}
		j++;
	}
	return (pos);
}

int	get_chunk_num(int min, int max)
{
	if (max - min <= 100)
		return (5);
	else
		return (11);
}

int	wich_chunk(int c, int min, int max)
{
	int	i;
	int	chunk_num;

	i = 1;
	chunk_num = get_chunk_num(min, max);
	while (i < chunk_num)
	{
		if (c < ((max - min) / chunk_num) * i)
			return (i);
		i++;
	}
	return (i);
}

void	get_min_max(t_element *elem, int *min, int *max)
{
	int			j;
	int			size;
	t_element	*list;

	j = 1;
	list = elem;
	*min = list->value;
	*max = list->value;
	size = ft_elem_size(elem);
	while (j < size && list->next != NULL)
	{
		list = list->next;
		if (list->value < *min)
			*min = list->value;
		else if (list->value > *max)
			*max = list->value;
		j++;
	}
}
