/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:18:35 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/20 16:26:04 by rel-bour         ###   ########.fr       */
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
    // int len_list;
    
        int len_list;
    int index_list;

    
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
#endif 