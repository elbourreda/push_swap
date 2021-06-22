/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:45:20 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/22 11:42:41 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_boucl(void)
{
	t_all	*all;
	int		i;
	// int		len_aa;
	int		count;

	// len_aa = all->len_a;
	i = 0;
	all = all_t();
	count = 0;
	get_new_list(all->list, all->t_c);
	while (i < all->len_a && count < all->len_list)
	{
		if (is_nbr_in_list(all->t_a[i], all->list) == 1)
		{
			send_it_to_b(all->t_a, all->t_b, i);
			count++;
			i = -1;
		}
		i++;
	}
}

void	send_it_to_a(int ta[], int tb[], int index)
{
	t_all	*all;
	int		midl;

	all = all_t();
	midl = all->len_b / 2;
	if (index <= midl)
	{
		while (index > 0)
		{
			rotate(tb, all->len_b, 'b');
			index--;
		}
	}
	else if (index > midl)
	{
		while (index < all->len_b)
		{
			reverce_rotate(tb, all->len_b, 'b');
			index++;
		}
	}
	push_a(all->t_a, all->t_b);
}

void	send_it_to_b(int ta[], int tb[], int index)
{
	t_all	*all;
	int		midl;

	all = all_t();
	midl = all->len_a / 2;
	if (index <= midl)
	{
		while (index > 0)
		{
			rotate(ta, all->len_a, 'a');
			index--;
		}
	}
	else if (index > midl)
	{
		while (index < all->len_a)
		{
			reverce_rotate(ta, all->len_a, 'a');
			index++;
		}
	}
	push_b(all->t_a, all->t_b);
}

void	half_sort_four(void)
{
	t_all	*all;

	all = all_t();
	push_b(all->t_a, all->t_b);
	sort_three();
	push_a(all->t_a, all->t_b);
}

void	sort_four(void)
{
	t_all	*all;
	int		min;
	int		index;

	all = all_t();
	min = min_number(all->t_a, all->len_a);
	index = get_index(all->t_a, all->len_a, min);
	if (index <= 2)
	{
		while (index > 0)
		{
			rotate(all->t_a, all->len_a, 'a');
			index--;
		}
	}
	else
	{
		while (index < all->len_a)
		{
			reverce_rotate(all->t_a, all->len_a, 'a');
			index++;
		}
	}
	half_sort_four();
}
