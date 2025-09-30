/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:05:42 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/16 17:05:42 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

// Utils

void	error_exit(int status_code, int *stack_a, int *stack_b);
int		is_str_int(char *str);
int		is_int_in_array(int *array, int size, int n);
int		get_smallest_idx(int *array, int size);
void	print_int_array(int *array, int size);
void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);

// Operations

void	do_sa(int *stack_a, int size_a);
void	do_sb(int *stack_b, int size_b);
void	do_ss(int *stack_a, int *stack_b, int size_a, int size_b);

void	do_pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	do_pb(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	do_ra(int *stack_a, int size_a);
void	do_rb(int *stack_b, int size_b);
void	do_rr(int *stack_a, int *stack_b, int size_a, int size_b);

void	do_rra(int *stack_a, int size_a);
void	do_rrb(int *stack_b, int size_b);
void	do_rrr(int *stack_a, int *stack_b, int size_a, int size_b);

// Sorting

void	test_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	small_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	big_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b);

#endif