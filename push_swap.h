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
void	print_stack(int *stack, int size, char l);
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

void	small_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	big_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b);

// Sorting Utils

void	clone_stack(int *dest, int *src, int src_size);
void	replace_stack_with_indexes(int *stack_a, int size_a, int *stack_c);
void	replace_stack_with_numbers(int *stack_a, int size_a, int *stack_c);
int		get_chunk_size(int size_a);
int		find_closest_chunk_element(int *stack, int size, int chunk_biggest_number);
void	bring_number_to_top(
	int		i,
	int		*stack,
	int		size,
	void	(*rotate)(int *, int),
	void	(*reverse_rotate)(int *, int),
	void	(*swap)(int *, int)
);
void	place_on_b(int *stack_a, int *stack_b, int *size_a, int *size_b, int chunk_median);
void	place_on_a(int *stack_a, int *stack_b, int *size_a, int *size_b);

// Quick Sort

void quicksort(int *arr, int low, int high);

#endif