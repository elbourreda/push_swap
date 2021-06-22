/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_part3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:49:20 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/22 11:48:39 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_20_to_150(void)
{
	t_all		*all;
	t_sort20	srt;

	srt.i = 0;
	all = all_t();
	all->index_list = 0;
	all->len_list = all->len_c / 6;
	srt.resl = all->len_c % all->len_list;
	if (srt.resl == 0)
		srt.p = all->len_c / all->len_list;
	else
		srt.p = (all->len_c / all->len_list) + 1;
	srt.i = -1;
	while (++srt.i < srt.p)
		while_boucl();
	srt.midl = 0;
	while (all->len_b > 0)
	{
		srt.midl = all->len_b / 2;
		srt.max = max_number(all->t_b, all->len_b);
		srt.index = get_index(all->t_b, all->len_b, srt.max);
		send_it_to_a(all->t_a, all->t_b, srt.index);
	}
}

void	sort_more(void)
{
	t_all		*all;
	t_sort20	srt;

	srt.i = 0;
	all = all_t();
	all->index_list = 0;
	all->len_list = all->len_c / 12;
	srt.resl = all->len_c % all->len_list;
	if (srt.resl == 0)
		srt.p = all->len_c / all->len_list;
	else
		srt.p = (all->len_c / all->len_list) + 1;
	srt.i = -1;
	while (++srt.i < srt.p)
		while_boucl();
	srt.midl = 0;
	while (all->len_b > 0)
	{
		srt.midl = all->len_b / 2;
		srt.max = max_number(all->t_b, all->len_b);
		srt.index = get_index(all->t_b, all->len_b, srt.max);
		send_it_to_a(all->t_a, all->t_b, srt.index);
	}
}
