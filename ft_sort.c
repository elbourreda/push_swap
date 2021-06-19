/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:17:09 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/19 21:46:57 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two()
{
    t_all *all;

	all = all_t();
    int min = min_number(all->t_a, all->len_a);
        
    if (min == all->t_a[1])
        swap_a_b(all->t_a, 'a');
}

void sort_three()
{
	t_all *all;

	all = all_t();
	int min = min_number(all->t_a, all->len_a);
	int max = max_number(all->t_a, all->len_a);
    if (max == all->t_a[0])
         rotate(all->t_a, all->len_a, 'a'); // RA RB
    else if (max == all->t_a[1])
        reverce_rotate(all->t_a, all->len_a, 'a'); // RRA RRB
    if (min == all->t_a[1])
        swap_a_b(all->t_a, 'a');
}

int get_index(int *ta, int len, int min)
{
	int i = 0;
	while (i < len)
	{
		if (ta[i] == min)
			return (i);
		i++;	
	}
	return (-1);
}

void sort_four()
{
    t_all *all;
	
	all = all_t();
    int min = min_number(all->t_a, all->len_a);
    int index = get_index(all->t_a, all->len_a, min);
    if (index <= 2)
	{
	  	while (index > 0)
	   	{
	   		rotate(all->t_a, all->len_a, 'a'); // RA RB
	   		index--;
	   	}
	}
	else if (index > 2)
	{
	   	while (index < all->len_a)
	   	{
	   		reverce_rotate(all->t_a, all->len_a, 'a'); // RRA RRB
	   		index++;
	   	}
	}
    push_b(all->t_a, all->t_b);
    sort_three();
    push_a(all->t_a, all->t_b);
    
}

void sort_five()
{
    t_all *all;
	
	all = all_t();
	int i = 0;
    while (i < 2)
    {
        int min = min_number(all->t_a, all->len_a);
        int index = get_index(all->t_a, all->len_a, min);
        if (index <= 2)
	    {
	    	while (index > 0)
	    	{
	    		rotate(all->t_a, all->len_a, 'a'); // RA RB
	    		index--;
	    	}
	    }
	    else if (index > 2)
	    {
	    	while (index < all->len_a)
	    	{
	    		reverce_rotate(all->t_a, all->len_a, 'a'); // RRA RRB
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

void get_new_list(int list[], int tc[])
{
	t_all *all;
	
	all = all_t();
	int i = 0;
	while (i < all->len_list)
	{
		// if (i == all->len_list)
		// {
		// 	list[i] = tc[all->index_list];
		// 	break;
		// }
		list[i] = tc[all->index_list];
		i++;
		all->index_list++;
	}
}

int is_nbr_in_list(int nb, int list[])
{
	int i = 0;
	t_all *all;
	
	all = all_t();
	while (i < all->len_list)
	{
		if (list[i] == nb)
			return (1);
		i++;
	}
	return (0);
	
}

void send_it_to_b(int ta[], int tb[], int index)
{
	t_all *all;
	
	all = all_t();
	int midl = all->len_a / 2;
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
void send_it_to_a(int ta[], int tb[], int index)
{
	t_all *all;
	
	all = all_t();
	int midl = all->len_b / 2;
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

void sort_6_to_20()
{
	t_all *all;
	
	all = all_t();
	int midl = 0;
	while (all->len_a > 0)
    {
		midl = all->len_a / 2;
        int min = min_number(all->t_a, all->len_a);
        int index = get_index(all->t_a, all->len_a, min);
        if (index <= midl)
	    {
	    	while (index > 0)
	    	{
	    		rotate(all->t_a, all->len_a, 'a'); // RA RB
	    		index--;
	    	}
	    }
	    else if (index > midl)
	    {
	    	while (index < all->len_a)
	    	{
	    		reverce_rotate(all->t_a, all->len_a, 'a'); // RRA RRB
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

void while_boucl()
{
	t_all *all;
	
	all = all_t();
	int i = 0;
	int len_aa = all->len_a;
	int count;
	
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

void sort_20_to_150()
{
	t_all *all;
	
	all = all_t();
	all->index_list = 0;
	int i = 0;
	all->len_list = all->len_c / 6;
	int len_aa = all->len_a;
	int p;
	int resl = all->len_c % all->len_list;
	if(resl == 0)
		p = all->len_c / all->len_list;
	else
		p = (all->len_c / all->len_list) + 1;
	i = 0;
	while (i < p )
	{
		while_boucl();
		i++;
	}
	int midl = 0;
	while (all->len_b > 0)
	{
		midl = all->len_b / 2;
		int max = max_number(all->t_b, all->len_b);
		int index = get_index(all->t_b, all->len_b, max);
		send_it_to_a(all->t_a, all->t_b, index);
	}
}

void sort_more()
{
	t_all *all;
	
	all = all_t();
	all->index_list = 0;
	int i = 0;
	all->len_list = all->len_c / 12;
	int len_aa = all->len_a;
	int p;
	int resl = all->len_c % all->len_list;
	if(resl == 0)
		p = all->len_c / all->len_list;
	else
		p = (all->len_c / all->len_list) + 1;
	i = 0;
	while (i < p )
	{
		while_boucl();
		i++;
	}
	int midl = 0;
	while (all->len_b > 0)
	{
		midl = all->len_b / 2;
		int max = max_number(all->t_b, all->len_b);
		int index = get_index(all->t_b, all->len_b, max);
		send_it_to_a(all->t_a, all->t_b, index);
	}
}