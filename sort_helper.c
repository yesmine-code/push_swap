#include "include/push_swap.h"

void	move_min_max(t_element **elem, int i, int choice)
{
	 while (i < ft_elem_size(*elem))
	{
		shift_up(elem);
		if (choice == 0)
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
		i++;
	}
}

void	move_min_max_up(t_element **elem, int pos, int choice)
{
	int	i;

	i = pos;
	if (pos < ft_elem_size(*elem) / 2)
	{
		while (i > 0)
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
		move_min_max(elem, i, choice);
}

void	shift_down_both_lists(t_element **elem1,
	int pos1, t_element **elem2, int pos2)
{
	int	i;
	int	j;

	i = pos1;
	j = pos2;
	while (i > 0 && j > 0)
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

void	shift_up_both_lists(t_element **elem1,
	int pos1, t_element **elem2, int pos2)
{
	int	i;
	int	j;

	i = pos1;
	j = pos2;
	while (i < ft_elem_size(*elem1) && j < ft_elem_size(*elem2))
	{
		shift_up(elem1);
		shift_up(elem2);
		ft_putstr_fd("rrr\n", 1);
		i++;
		j++;
	}
	while (i < ft_elem_size(*elem1))
	{
		shift_up(elem1);
		ft_putstr_fd("rra\n", 1);
		i++;
	}
	while (j < ft_elem_size(*elem2))
	{
		shift_up(elem2);
		ft_putstr_fd("rrb\n", 1);
		j++;
	}
}

void	move_lists_up(t_element **elem1, int pos1, t_element **elem2, int pos2)
{
	if (pos1 < ft_elem_size(*elem1) / 2 && pos2 < ft_elem_size(*elem2) / 2)
		shift_down_both_lists(elem1, pos1, elem2, pos2);
	else if (pos1 >= ft_elem_size(*elem1) / 2
		&& pos2 >= ft_elem_size(*elem2) / 2)
		shift_up_both_lists(elem1, pos1, elem2, pos2);
	else
	{
		move_min_max_up(elem1, pos1, 0);
		move_min_max_up(elem2, pos2, 1);
	}
}
