/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:39:47 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/19 21:47:51 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap_a_b(int *table, char o)
{
	int tmp;
	t_all *all;
	
	all = all_t();
	tmp = table[0];
	table[0] = table[1];
	table[1] = tmp;
	if (o == 'a')
		write(1, "sa\n", 3);
	else if (o == 'b')
		write(1, "sb\n", 3);
}

void	rotate(int table_a[], int len, char o)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = table_a[0];
	while (i < len)
	{
		table_a[i] = table_a[i + 1];
		i++;
	}
	table_a[len - 1] = tmp;
	if (o == 'a')
		write(1, "ra\n", 3);
	else if (o == 'b')
		write(1, "rb\n", 3);
}

void	reverce_rotate(int table_a[], int len, char o)
{
	int	tmp;
	int	i;

	i = len;
	tmp = table_a[len - 1];
	while (i > 0)
	{
		table_a[i] = table_a[i - 1];
		i--;
	}
	table_a[0] = tmp; 
	if (o == 'a')
		write(1, "rra\n", 4);
	else if (o == 'b')
		write(1, "rrb\n", 4);
}

void	push_a(int table_a[], int table_b[])
{
	int tmp;
	int	i;
	t_all *all;

	all = all_t();
	tmp = table_b[0];


	all->len_a++;
	i = all->len_a;
	while (i > 0)
	{
		table_a[i] = table_a[i - 1];
		i--;
	}
	table_a[0] = tmp;
	
	
	i = 0;
	while (i < all->len_b)
	{
		table_b[i] = table_b[i + 1];
		i++;
	}
	all->len_b--;
	write(1, "pa\n", 3);
}

void	push_b(int table_a[], int table_b[])
{
	int tmp;
	int	i;
	t_all *all;

	all = all_t();
	tmp = table_a[0];
	all->len_b++;
	i = all->len_b;
	while (i > 0)
	{
		table_b[i] = table_b[i - 1];
		i--;
	}
	table_b[0] = tmp;
		i = 0;
	while (i < all->len_a)
	{
		table_a[i] = table_a[i + 1];
		i++;
	}
	all->len_a--;
	write(1, "pb\n", 3);
}

void	push_ad(int ta[], int tb[])
{
	
	t_all *all;

	all = all_t();
	char c = tb[0];
	int i = 0;
	
	while (i < (all->len_b))
	{
		tb[i] = tb[i + 1];
		i++;
	}
	i = 0;
	while(i < all->len_a)
	{
		printf("===%d===", ta[i + 1]);
		ta[i + 1] = ta[i];
		i++;		
	}
	ta[0] = c;
	all->len_b--;
	all->len_a++;
}