#include "include/push_swap.h"

void	other_cases(t_element **list_a, int a, int b, int c)
{
	if (a < b && c < b && c < a)
	{
		shift_up(list_a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (c > a && c > b && a > b)
	{
		stack_swap(*list_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (a > b && b > c && a > c)
	{
		stack_swap(*list_a);
		ft_putstr_fd("sa\n", 1);
		shift_up(list_a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	sort_three(t_element **list_a)
{
	int			a;
	int			b;
	int			c;
	t_element	*elem;

	elem = (*list_a)->next;
	a = (*list_a)->value;
	b = elem->value;
	c = elem->next->value;
	if (a > b && a > c && b < c)
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
	other_cases(list_a, a, b, c);
}

void	sort_five(t_element **list_a, t_element **list_b)
{
	int	pos;
	int	i;

	i = 0;
	while (ft_elem_size(*list_a) > 3)
	{
		pos = find_min_max(*list_a, 0);
		move_min_max_up(list_a, pos, 0);
		if (is_sorted(*list_a, 0) == 0)
		{
			stack_push(list_a, list_b);
			ft_putstr_fd("pb\n", 1);
			i++;
		}
		else
			break ;
	}
	sort_three(list_a);
	while (i > 0)
	{
		stack_push(list_b, list_a);
		ft_putstr_fd("pa\n", 1);
		i--;
	}
}

void	ft_sort(int ac, t_element *list_a, t_element *list_b)
{
	if (ac == 3 && list_a->value > list_a->next->value)
		stack_swap(list_a);
	if (ac == 4)
		sort_three(&list_a);
	if (ac <= 6)
		sort_five(&list_a, &list_b);
	else
		sort_list(&list_a, &list_b);
}

int	main(int ac, char **av)
{
	t_element	*list_a;
	t_element	*list_b;
	int			i;

	list_a = NULL;
	list_b = NULL;
	i = 0;
	if (ac == 1 || ac == 2)
		exit (EXIT_SUCCESS);
	while (i < ac - 1)
	{
		if (check_if_int(av[i + 1]) == 0)
			ft_error();
		ft_add_element(&list_a, ft_atoi(av[i + 1]));
		i++;
	}
	case_of_doublon(list_a, list_b);
	ft_sort(ac, list_a, list_b);
	ft_free(list_a, list_b);
	exit (EXIT_SUCCESS);
}
