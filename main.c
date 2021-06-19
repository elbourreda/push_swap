/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:15:22 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/19 21:48:22 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*all_t(void)
{
	static t_all	all;

	return (&all);
}

int	max_number(int *av, int len)
{
	int	max;
	int	i;

	i = 1;
	max = av[0];
	while (i < len)
	{
		if (max < av[i])
			max = av[i];
		i++;
	}
	return (max);
}

int	min_number(int *av, int len)
{
	int	min;
	int	i;

	i = 1;
	min = av[0];
	while (i < len)
	{
		if (min > av[i])
			min = av[i];
		i++;
	}
	return (min);
}

void	add_to_table_int(char *av[], char c)
{
	int		i;
	t_all	*all;
	
	i = 1;
	all = all_t();
    if (c == 'a')
    {
        while (i <= all->len_a)
        {
            all->t_a[i - 1] = atoi(av[i]);
            i++;
        }
    }
    else
    {
        while (i <= all->len_c)
        {
            all->t_c[i - 1] = atoi(av[i]);
            i++;
        }
    }
}

void	sort_tc(int tc[])
{
	int i;
	int j;
	int pos;
	int min;
	int swap;
	t_all *all;

	all = all_t();
	i = 0;
	while (i < all->len_c)
	{
		j = i;
		min = tc[j];
		pos = j;
		while (j < all->len_c)
		{
			if (tc[j] < min)
			{
				min = tc[j];
				pos = j;
			}
			j++;
		}
		if (pos != i)
		{
			swap = tc[i];
			tc[i] = tc[pos];
			tc[pos] = swap;
		}
		i++;
	}
}

void initial(int ac, char **av)
{
    t_all *all;
	
	all = all_t();
    all->len_a = ac - 1;
    all->len_b = 0;
    all->len_c = all->len_a;
    all->t_a = (int *)malloc(sizeof(int *) * ac);
    all->t_b = (int *)malloc(sizeof(int *) * ac);
    all->t_c = (int *)malloc(sizeof(int *) * ac);
    all->list = (int *)malloc(sizeof(int *) * ac);
    add_to_table_int(av, 'a');
    add_to_table_int(av, 'c');
    sort_tc(all->t_c);
}

int main(int ac, char **av)
{
    t_all *all;
	int i = 0;

	all = all_t();
    if (ac > 2)
    {
        initial(ac, av);
        if (all->len_a == 2)
            sort_two();
        else if (all->len_a == 3)
            sort_three();
        else if (all->len_a == 4)
            sort_four();
        else if (all->len_a == 5)
            sort_five();
        else if (all->len_a >= 6 && all->len_a < 20)
            sort_6_to_20();
        else if (all->len_a >= 20 && all->len_a <= 150)
            sort_20_to_150();
        else if (all->len_a >= 150)
            sort_more();
    }
    return (0);
}