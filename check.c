#include "include/push_swap.h"

int	check_if_int(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+' || ft_isdigit(arg[0]) == 1)
		i++;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(arg) == -1 && ft_strlen(arg) > 2)
		return (0);
	return (1);
}

int	check_if_doublon(t_element *elem)
{
	t_element	*list;
	t_element	*list2;
	int			tmp1;
	int			tmp2;

	list = elem;
	while (list->next != NULL)
	{
		list2 = list->next;
		tmp1 = list->value;
		while (list2 != NULL)
		{
			tmp2 = list2->value;
			if (tmp1 == tmp2)
				return (0);
			list2 = list2->next;
		}
		list = list->next;
	}
	return (1);
}

int	is_sorted(t_element *elem, int choice)
{
	int			i;
	int			size;
	t_element	*el;

	el = elem;
	size = ft_elem_size(elem);
	i = 0;
	while (i < size - 1 && el->next != NULL)
	{
		if (choice == 0 && el->value > el->next->value)
			return (0);
		else if (choice == 1 && el->value < el->next->value)
			return (0);
		el = el->next;
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	printf("ERROR\n");
	exit(EXIT_FAILURE);
}

void	case_of_doublon(t_element *list_a, t_element *list_b)
{
	if (check_if_doublon(list_a) == 0)
	{
		ft_free(list_a, list_b);
		ft_error();
	}
}
