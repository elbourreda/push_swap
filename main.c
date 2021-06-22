/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:15:22 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/21 15:50:40 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*all_t(void)
{
	static t_all	all;

	return (&all);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
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



void	add_to_table_int(char **av, char c)
{
	int		i;
	t_all	*all;

	i = 0;
	all = all_t();
	if (c == 'a')
	{
		while (i < all->len_a)
		{
			all->t_a[i] = ft_atoi(av[i]);
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
	t_all	*all;

	all = all_t();
	all->i = -1;
	while (++all->i < all->len_c)
	{
		all->j = all->i;
		all->min = tc[all->j];
		all->pos = all->j;
		while (++all->j < all->len_c)
		{
			if (tc[all->j] < all->min)
			{
				all->min = tc[all->j];
				all->pos = all->j;
			}
		}
		if (all->pos != all->i)
		{
			all->swap = tc[all->i];
			tc[all->i] = tc[all->pos];
			tc[all->pos] = all->swap;
		}
	}
}

void check_if_list_sorted()
{
	int	i;
	t_all	*all;

	all = all_t();

	i = 0;
	while (i < all->len_a)
	{
		if (all->t_a[i] != all->t_c[i])
			return ;
		i++;
	}
	exit(1);
}

void	initial(int ac, char **av)
{
	t_all	*all;

	all = all_t();
	all->len_a = all->ac;
	all->len_b = 0;
	all->len_c = all->len_a;
	all->t_a = (int *)malloc(sizeof(int *) * all->ac);
	all->t_b = (int *)malloc(sizeof(int *) * all->ac);
	all->t_c = (int *)malloc(sizeof(int *) * all->ac);
	all->list = (int *)malloc(sizeof(int *) * all->ac);
	add_to_table_int(av, 'a');
	add_to_table_int(av, 'c');
	sort_tc(all->t_c);
	check_if_list_sorted();
	
}

void	norm_list(char **ar)
{
	int		i;
	int		j;
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
	j = 0;
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
	int		i;
	t_all	*all;
	int		c;
	int		c2;

	all = all_t();
	c = 0;
	c2 = 0;
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
	int		i;
	char	**ar;
	int		c;
	t_all	*all;

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
		return (1);
	else
		return (0);
}

void	check_error(void)
{
	t_all	*all;
	int		o;
	int		k;

	all = all_t();
	o = 0;
	while (all->args[o])
	{
		 k = 0;
		if (all->args[o][k] == '-' || all->args[o][k] == '+')
		{
			k++;
			if (all->args[o][k] == '\0')
				print_error();
		}
		while (all->args[o][k])
		{
			if (ft_isdigit(all->args[o][k]) == 0 )
				print_error();
			k++;
		}
		o++;
	}
}

void	check_double(void)
{
	t_all	*all;
	int		i;
	int		j;

	all = all_t();
	i = 0;
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

int	main(int ac, char **av)
{
	t_all	*all;

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