/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:18:35 by rel-bour          #+#    #+#             */
/*   Updated: 2021/06/18 19:56:07 by rel-bour         ###   ########.fr       */
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
    char *list;
    int len_list;
    
}   t_all;


void	swap_a_b(int *table, char o);
void	rotate(int table_a[], int len, char o);
// void	reverce_rotate(int table_a[], int len);
void	reverce_rotate(int table_a[], int len, char o);
void	push_b(int table_a[], int table_b[]);
void	push_a(int ta[], int tb[]);
t_all	*all_t(void);


int	min_number(int *av, int len);
int	max_number(int *av, int len);
void sort_two();
void sort_three();
void sort_five();
#endif 