/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:17:09 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/21 16:03:19 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(void)
{
	t_all	*all;
	int		i;
	int		min;
	int		index;

	i = 0;
	all = all_t();
	while (i < 2)
	{
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
		else if (index > 2)
		{
			while (index < all->len_a)
			{
				reverce_rotate(all->t_a, all->len_a, 'a');
				index++;
			}
		}
		push_b(all->t_a, all->t_b);
		i++;
	}
	sort_three();
	push_a(all->t_a, all->t_b);
	push_a(all->t_a, all->t_b);
}

void	sort_6_to_20(void)
{
	t_all	*all;
	int		min;
	int		index;
	int		midl;

	midl = 0;
	all = all_t();
	while (all->len_a > 0)
	{
		midl = all->len_a / 2;
		min = min_number(all->t_a, all->len_a);
		index = get_index(all->t_a, all->len_a, min);
		if (index <= midl)
		{
			while (index > 0)
			{
				rotate(all->t_a, all->len_a, 'a');
				index--;
			}
		}
		else if (index > midl)
		{
			while (index < all->len_a)
			{
				reverce_rotate(all->t_a, all->len_a, 'a');
				index++;
			}
		}
		push_b(all->t_a, all->t_b);
	}
	while (all->len_b > 0)
	{
		push_a(all->t_a, all->t_b);
	}
}

// void	sort_20_to_150(void)
// {
// 	t_all	*all;
// 	int		index;
// 	int		max;
// 	int		midl;
// 	int		i;
// 	int		p;
// 	int		len_aa;
// 	int		resl;

// 	i = 0;
// 	all = all_t();
// 	all->index_list = 0;
// 	all->len_list = all->len_c / 6;
// 	len_aa = all->len_a;
// 	resl = all->len_c % all->len_list;
// 	if (resl == 0)
// 		p = all->len_c / all->len_list;
// 	else
// 		p = (all->len_c / all->len_list) + 1;
// 	i = 0;
// 	while (i < p)
// 	{
// 		while_boucl();
// 		i++;
// 	}
// 	 midl = 0;
// 	while (all->len_b > 0)
// 	{
// 		midl = all->len_b / 2;
// 		max = max_number(all->t_b, all->len_b);
// 		index = get_index(all->t_b, all->len_b, max);
// 		send_it_to_a(all->t_a, all->t_b, index);
// 	}
// }

// void	sort_more(void)
// {
// 	t_all	*all;
// 	int		index;
// 	int		max;
// 	int		midl;
// 	int		i;
// 	int		p;
// 	int		len_aa;
// 	int		resl;

// 	i = 0;
// 	all = all_t();
// 	all->index_list = 0;
// 	all->len_list = all->len_c / 12;
// 	len_aa = all->len_a;
// 	resl = all->len_c % all->len_list;
// 	if (resl == 0)
// 		p = all->len_c / all->len_list;
// 	else
// 		p = (all->len_c / all->len_list) + 1;
// 	i = 0;
// 	while (i < p)
// 	{
// 		while_boucl();
// 		i++;
// 	}
// 	midl = 0;
// 	while (all->len_b > 0)
// 	{
// 		midl = all->len_b / 2;
// 		max = max_number(all->t_b, all->len_b);
// 		index = get_index(all->t_b, all->len_b, max);
// 		send_it_to_a(all->t_a, all->t_b, index);
// 	}
// }
