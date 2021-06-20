/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parrot <parrot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:15:22 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/20 02:36:23 by parrot           ###   ########.fr       */
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

void	add_to_table_int(char **av, char c)
{
	int		i;
	t_all	*all;
	
	i = 0;
	all = all_t();
				// printf("%d||\n", all->len_a);

    if (c == 'a')
    {
        while (i < all->len_a)
        {
            all->t_a[i] = atoi(av[i]);
            i++;
        }
    }
    else
    {
        while (i < all->len_c)
        {
            all->t_c[i] = atoi(av[i]);
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
    all->len_a = all->ac;
			// printf("%d|%d\n", ac, all->len_a);

    all->len_b = 0;
    all->len_c = all->len_a;
    all->t_a = (int *)malloc(sizeof(int *) * all->ac);
    all->t_b = (int *)malloc(sizeof(int *) * all->ac);
    all->t_c = (int *)malloc(sizeof(int *) * all->ac);
    all->list = (int *)malloc(sizeof(int *) * all->ac);
		add_to_table_int(av, 'a');
		add_to_table_int(av, 'c');
		sort_tc(all->t_c);
}



void	norm_list(char **ar)
{
	LONG_L	i;
	t_all	*all;

	all = all_t();
	i = 0;
	while (all->args && all->args[i])
	{
		all->tmp[i] = all->args[i];
		i++;
	}
	free(all->args);
	all->args = NULL;
	int j = 0;
	while (ar[j])
	{
		all->tmp[i] = ar[j];
		i++;
		j++;
	}
	all->tmp[i] = NULL;
	all->args = all->tmp;


	
}

void	add_in_list(char **ar)
{
	LONG_L	i;
	t_all	*all;

	all = all_t();
	int c = 0;
	int c2 = 0;
	i = -1;
	if (!ar)
		return ;
	while (ar[++i])
		c++;
	i = -1;
	while (all->args && all->args[++i])
		c2++;
	all->tmp = malloc(sizeof(char *) * (c + c2 + 1));
	norm_list(ar);
}

void	rem_args(char **av)
{
	int			i;
	char		**ar;
	int		c;
	t_all		*all;

	all = all_t();
	i = 0;
	c = 0;
	while (av[++i])
	{
		ar = ft_split(av[i], ' ');
		add_in_list(ar);
		free(ar);
	}
	i = -1;
	while (all->args[++i])
		c++;
	all->ac = c;
}

int	ft_isdigit(char number)
{
	if ((number >= '0' && number <= '9'))
	{
		return (1);
	}
	else
		return (0);
}

void check_error()
{
	t_all *all;

	all = all_t();
	int o = 0;
	while (all->args[o])
	{
		int k = 0;
		if (all->args[o][k] == '-' || all->args[o][k] ==  '+')
			k++; 
		while (all->args[o][k])
		{
			if (ft_isdigit(all->args[o][k]) == 0 )
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			k++;
		}
		o++;
	}
}

void check_double()
{
	t_all *all;
	int i = 0;
	int j = 0;
	
	all = all_t();
	while (i < all->len_a)
	{
		j = i + 1;
		while (j < all->len_a)
		{
			if (all->t_a[i] == all->t_a[j])
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;	
		}
		i++;
	}
}

int main(int ac, char **av)
{
    t_all *all;
	int i = 0;

	all = all_t();
    if (ac > 1)
    {
		rem_args(av);
		check_error();
        initial(all->ac, all->args);
		check_double();
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