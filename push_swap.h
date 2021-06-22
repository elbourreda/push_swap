/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:18:35 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/21 15:51:50 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_all
{
    int len_a;
    int len_b;
    int len_c;
    int *t_a;
    int *t_b;
    int *t_c;
    int *list;
    int ac;
    char **args;
    char **tmp;
    int	swap;
    int	pos;
    int len_list;
    int index_list;
    int	i;
	int	j;
	int	min;
    
}   t_all;


void	swap_a_b(int *table, char o);
void	rotate(int table_a[], int len, char o);
// void	reverce_rotate(int table_a[], int len);
void	reverce_rotate(int table_a[], int len, char o);
void	push_b(int table_a[], int table_b[]);
void	push_a(int ta[], int tb[]);
t_all	*all_t(void);

char			**ft_split(char const *s, char c);
int	min_number(int *av, int len);
int	max_number(int *av, int len);
void sort_two();
void sort_three();
void sort_five();
void sort_four();
void sort_6_to_20();
void	push_a(int table_a[], int table_b[]);
void sort_20_to_150();
void sort_more();
void	sort_two(void);
void	sort_three(void);;
int	get_index(int *ta, int len, int min);
void	get_new_list(int list[], int tc[]);
int	is_nbr_in_list(int nb, int list[]);


void	while_boucl(void);
void	send_it_to_a(int ta[], int tb[], int index);
void	send_it_to_b(int ta[], int tb[], int index);
void	sort_four(void);

int	min_number(int *av, int len);
void	check_nmbr_max(long long nb);
void	check_nmbr_max2(char *nb, char i);
int	return_atoi(int sing);
int	ft_atoi(char *str);
void	print_error(void);




#endif 