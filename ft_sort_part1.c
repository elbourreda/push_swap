/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:42:46 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/21 14:44:18 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(void)
{
	t_all	*all;
	int		min;

	all = all_t();
	min = min_number(all->t_a, all->len_a);
	if (min == all->t_a[1])
		swap_a_b(all->t_a, 'a');
}

void	sort_three(void)
{
	t_all	*all;
	int		min;
	int		max;

	all = all_t();
	min = min_number(all->t_a, all->len_a);
	max = max_number(all->t_a, all->len_a);
	if (max == all->t_a[0])
		rotate(all->t_a, all->len_a, 'a');
	else if (max == all->t_a[1])
		reverce_rotate(all->t_a, all->len_a, 'a');
	if (min == all->t_a[1])
		swap_a_b(all->t_a, 'a');
}

int	get_index(int *ta, int len, int min)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ta[i] == min)
			return (i);
		i++;
	}
	return (-1);
}

void	get_new_list(int list[], int tc[])
{
	t_all	*all;
	int		i;

	all = all_t();
	i = 0;
	while (i < all->len_list)
	{
		list[i] = tc[all->index_list];
		i++;
		all->index_list++;
	}
}

int	is_nbr_in_list(int nb, int list[])
{
	int		i;
	t_all	*all;

	i = 0;
	all = all_t();
	while (i < all->len_list)
	{
		if (list[i] == nb)
			return (1);
		i++;
	}
	return (0);
}
