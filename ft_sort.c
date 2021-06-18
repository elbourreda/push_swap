/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:17:09 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/18 20:51:58 by rel-bour         ###   ########.fr       */
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


void sort_five()
{
    t_all *all;
	
	all = all_t();
    // while (all->len_a > 0)
    // {
    //     int min = min_number(all->t_a, all->len_a);
    //     int index = get_index(all->t_a, all->len_a, min);
    //     if (index <= 2)
	//     {
	//     	while (index > 0)
	//     	{
	//     		rotate(all->t_a, all->len_a, 'a'); // RA RB
	//     		index--;
	//     	}
	//     }
	//     else if (index > 2)
	//     {
	//     	while (index < all->len_a)
	//     	{
	//     		reverce_rotate(all->t_a, all->len_a, 'a'); // RRA RRB
	//     		index++;
	//     	}
	//     }
    //     push_b(all->t_a, all->t_b);
    // }
    // while (all->len_b > 0)
    // {
    //        push_a(all->t_a, all->t_b);
    // }


    while (all->len_a > 0)
    {
        push_b(all->t_a, all->t_b);
    }
    push_a(all->t_a, all->t_b);
    push_a(all->t_a, all->t_b);
    push_a(all->t_a, all->t_b);
    // while (all->len_b > 0)
    // {
    //        push_a(all->t_a, all->t_b);
    // }
   
    
    
    
}