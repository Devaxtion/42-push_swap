/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:05:42 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/25 15:23:19 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

// Stack Structure

typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}	t_stack;

// Print

void	print_int_array(int *array, int size);
void	print_stack(t_stack *stack, char l);
void	print_stacks(t_stack *a, t_stack *b);

// Errors

# define ERR_ALLOC 1
# define ERR_INVALID_INT 2
# define ERR_DUPLICATE 3

void	cleanup_and_exit(int status_code, t_stack *a, t_stack *b);

// Initialization

void	init_stacks(int argc, char **argv, t_stack *a, t_stack *b);

// Array Utils

int		*ft_arraydup(int *src, int size);
int		is_array_sorted(int *array, int size);
int		get_smallest_idx(int *array, int size);
int		find_n_in_array(int *array, int size, int n);

// Operations

void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_ss(t_stack *a, t_stack *b);

void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);

void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_rr(t_stack *a, t_stack *b);

void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);

// Operation Utils

void	push_elements_down(t_stack *stack);
void	push_elements_up(t_stack *stack);

// Sorting

void	sort(t_stack *a, t_stack *b);

// Stack Utils

void	rank_encode(int *stack_a, int size_a, int *sorted_stack);
void	rank_decode(int *stack_a, int size_a, int *sorted_stack);
void	bring_number_to_top(
			int idx,
			t_stack *stack,
			void (*rotate)(t_stack *),
			void (*reverse_rotate)(t_stack *)
			);
void	place_on_a(t_stack *a, t_stack *b);
void	place_on_b(t_stack *a, t_stack *b, int chunk_median);

// Chunk Utils

int		get_chunk_size(int size_a);
void	move_chunk_to_b(t_stack *a, t_stack *b, int chunk_size, int chunk_idx);

// Quick Sort

void	quicksort(int *array, int low, int high);

#endif