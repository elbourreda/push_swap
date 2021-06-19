/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parrot <parrot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:17:09 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/19 02:22:03 by parrot           ###   ########.fr       */
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
    while (all->len_a > 0)
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
    }
    while (all->len_b > 0)
        push_a(all->t_a, all->t_b);
}

// void sort_6_to_20()
// {
    
// }


/////***reda


void get_new_list(int list[], int tc[])
{
	t_all *all;
	
	all = all_t();
	int i = 0;
	// printf("%d]]", all->index_list);
	while (i < all->len_list && all->t_a > 0)
	{
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
	if (index <= (all->len_a / 2))
	{
		while (index > 0)
		{
			rotate(ta, all->len_a, 'a');
			index--;
		}
	}
	else if (index > (all->len_a / 2))
	{
		while (index < all->len_a)
		{
			reverce_rotate(ta, all->len_a, 'a');
			index++;
		}
	}
}

void sort_6_to_20()
{
	t_all *all;
	
	all = all_t();
    all->len_list = 5;
	int list[all->len_list];
	int count = all->len_c / all->len_list;
	all->index_list = 0;
	int i = 0;
	int l = 0;
	int lenlisttmp = all->len_list; 
    int jj = 0;
	// while (l < count)
	// {
	// 	get_new_list(list, all->t_c);
	// 	i = 0;
	// 	int len = all->len_a;
	// 	while(i < len && lenlisttmp > 0)
	// 	{
	// 		if (is_nbr_in_list(all->t_a[i], list) == 1)
	// 		{
	// 			send_it_to_b(all->t_a, all->t_b, i);
	// 			push_b(all->t_a, all->t_b);
	// 			lenlisttmp--;
	// 			i = 0;
	// 		}
	// 		i++;
	// 	}
	// 	// jj = all->index_list + 5;
	// 	// printf("\n%d=\n", all->len_list);
	// 	l++;
	// }

    while (l < count)
	{
		get_new_list(list, all->t_c);
		i = 0;
        lenlisttmp = all->len_list;
		int len = all->len_a;
		while(i < len && lenlisttmp > 0)
		{
			if (is_nbr_in_list(all->t_a[i], list) == 1)
			{
				send_it_to_b(all->t_a, all->t_b, i);
				push_b(all->t_a, all->t_b);
				lenlisttmp--;
				i = 0;
			}
			i++;
		}
		// jj = all->index_list + 5;
		printf("\n%d=\n", lenlisttmp);
		l++;
	}
    




    // int j  = 0;
	// while(j < all->len_list)
	// {
	// 	printf("%d ", list[j]);
	// 	j++;
	// }

	// int j  = 0;
	// while(j < all->len_a)
	// {
	// 	printf("%d ", ta[j]);
	// 	j++;
	// }
}