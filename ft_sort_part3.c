/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_part3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:49:20 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/22 11:42:02 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_sort_20
{
	int	index;
	int	max;
	int	midl;
	int	i;
	int	p;
	int	resl;
}	t_sort20;

void	half_sort_20_to_150()
{
	
}

void	sort_20_to_150(void)
{
	t_all	*all;
	int		index;
	int		max;
	int		midl;
	int		i;
	int		p;
	// int		len_aa;
	int		resl;

	all = all_t();
	all->index_list = 0;
	all->len_list = all->len_c / 6;
	// len_aa = all->len_a;
	resl = all->len_c % all->len_list;
	if (resl == 0)
		p = all->len_c / all->len_list;
	else
		p = (all->len_c / all->len_list) + 1;
	i = 0;
	while (i < p)
	{
		while_boucl();
		i++;
	}
	midl = 0;
	while (all->len_b > 0)
	{
		midl = all->len_b / 2;
		max = max_number(all->t_b, all->len_b);
		index = get_index(all->t_b, all->len_b, max);
		send_it_to_a(all->t_a, all->t_b, index);
	}
}

void	sort_more(void)
{
	t_all	*all;
	int		index;
	int		max;
	int		midl;
	int		i;
	int		p;
	// int		len_aa;
	int		resl;

	all = all_t();
	all->index_list = 0;
	all->len_list = all->len_c / 12;
	// len_aa = all->len_a;
	resl = all->len_c % all->len_list;
	if (resl == 0)
		p = all->len_c / all->len_list;
	else
		p = (all->len_c / all->len_list) + 1;
	i = 0;
	while (i < p)
	{
		while_boucl();
		i++;
	}
	midl = 0;
	while (all->len_b > 0)
	{
		midl = all->len_b / 2;
		max = max_number(all->t_b, all->len_b);
		index = get_index(all->t_b, all->len_b, max);
		send_it_to_a(all->t_a, all->t_b, index);
	}
}
