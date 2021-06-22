/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:50:06 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/21 15:54:26 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_nmbr_max(long long nb)
{
	if (nb > 2147483647)
		print_error();
	else if (nb < -2147483648)
		print_error();
}

void	check_nmbr_max2(char *nb, char i)
{
	int	len;

	len = 0;
	while (nb[i] == '0')
		i++;
	while (nb[i] && nb[i] >= '0' && nb[i] <= '9')
	{
		len++;
		i++;
	}
	if (len > 10)
		print_error();
}

int	return_atoi(int sing)
{
	if (sing > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	long long	rslt;
	int			sign;
	int			cnt;

	rslt = 0;
	sign = 1;
	cnt = 0;
	if (str[cnt] == '-')
	{
		cnt++;
		sign = -1;
	}
	else if (str[cnt] == '+')
		cnt++;
	check_nmbr_max2(str, cnt);
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		rslt = rslt * 10 + (str[cnt] - '0');
		cnt++;
	}
	check_nmbr_max(rslt * sign);
	return (rslt * sign);
}
