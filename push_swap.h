/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:05:42 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/13 14:07:02 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

// Errors

#define ERR_ALLOC 1
#define ERR_INVALID_INT 2
#define ERR_DUPLICATE 3

// Input

void	init_stacks(int argc, char **argv, int **stack_a, int **stack_b, int *size_a, int *size_b);

// Utils

void	cleanup_and_exit(int status_code, int *stack_a, int *stack_b);
int		is_array_sorted(int *array, int size);
int		get_smallest_idx(int *array, int size);
void	copy_int_array(int *dest, int *src, int src_size);
int		find_n_in_array(int *array, int size, int n);

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

void	sort(int *stack_a, int *stack_b, int *size_a, int *size_b);

// Sorting Utils

void	bring_number_to_top(
	int		i,
	int		*stack,
	int		size,
	void	(*rotate)(int *, int),
	void	(*reverse_rotate)(int *, int),
	void	(*swap)(int *, int)
);
void	place_on_a(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	place_on_b(int *stack_a, int *stack_b, int *size_a, int *size_b, int chunk_median);

// Sorted Stack

int		*create_sorted_stack(int *stack, int size);
void	replace_stack_with_indexes(int *stack_a, int size_a, int *stack_c);
void	replace_stack_with_elements(int *stack_a, int size_a, int *stack_c);

// Chunk Utils

int		get_chunk_size(int size_a);
void	move_chunk_to_b(int *stack_a, int *stack_b, int *size_a, int *size_b, int chunk_size, int chunk_idx);

// Quick Sort

void	quicksort(int *array, int low, int high);

#endif