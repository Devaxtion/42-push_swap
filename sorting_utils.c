/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:43:58 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/02 12:43:58 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(int *stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack[i] < stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int		get_smallest_idx(int *array, int size)
{
	int	smallest_idx;
	int	i;

	smallest_idx = 0;
	i = 1;
	while (i < size)
	{
		if (array[i] < array[smallest_idx])
			smallest_idx = i;
		i++;
	}
	return (smallest_idx);
}

int	*create_sorted_stack(int *stack, int size)
{
	int	*sorted;

	sorted = ft_calloc(size, sizeof(int));
	if (!sorted)
		cleanup_and_exit(ERR_ALLOC, stack, NULL);
	clone_stack(sorted, stack, size);
	quicksort(sorted, 0, size - 1);
	return (sorted);
}

void	clone_stack(int *dest, int *src, int src_size)
{
	int	i;

	i = 0;
	while (i < src_size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	replace_stack_with_indexes(int *stack_a, int size_a, int *stack_c)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (stack_c[j] != stack_a[i])
			j++;
		stack_a[i] = j;
		i++;
	}
}

void	replace_stack_with_numbers(int *stack_a, int size_a, int *stack_c)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		stack_a[i] = stack_c[i];
		i++;
	}
}

int	get_chunk_size(int size_a)
{
	if (size_a <= 100)
		return (size_a / 5);   // 20 per chunk (5 chunks)
	else
		return (size_a / 11);  // ~45 per chunk (11 chunks)
}

void	move_chunk_to_b(int *stack_a, int *stack_b, int *size_a, int *size_b, int chunk_size, int chunk_idx)
{
	int	chunk_biggest_number;
	int	chunk_median;
	int	closest_number_idx;

	chunk_biggest_number = (chunk_size * (chunk_idx + 1) - 1);
	chunk_median = chunk_biggest_number - chunk_size / 2;
	while (1)
	{
		// find the closest number to the top or bottom (from current chunk)
		// If it didn't find, break
		closest_number_idx = find_closest_chunk_element(stack_a, *size_a, chunk_biggest_number);
		if (closest_number_idx == -1)
			break;
		bring_number_to_top(closest_number_idx, stack_a, *size_a, do_ra, do_rra, do_sa);
		place_on_b(stack_a, stack_b, size_a, size_b, chunk_median);
	}
}

int	find_closest_chunk_element(int *stack, int size, int chunk_biggest_number)
{
	int	i;
	int	j;

	if (size <= 0)
		return (-1);
	
	i = 0;
	while (i < size)
	{
		j = size - 1 - i;
		if (stack[i] <= chunk_biggest_number)
			return (i);
		if (stack[j] <= chunk_biggest_number)
			return (j);
		i++;
	}
	return (-1);
}

void	place_on_b(int *stack_a, int *stack_b, int *size_a, int *size_b, int chunk_median)
{
	// if there is nothing on B, just push B
	if (*size_b == 0)
		return (do_pb(stack_a, stack_b, size_a, size_b));
	
	// if A[0] > median, push B
	if (stack_a[0] > chunk_median)
		do_pb(stack_a, stack_b, size_a, size_b);

	// else (A[0] < median), push B and rotate B
	else
	{
		do_pb(stack_a, stack_b, size_a, size_b);
		do_rb(stack_b, *size_b);
	}
}

int	find_n_in_array(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

void	bring_number_to_top(
	int		i,
	int		*stack,
	int		size,
	void	(*rotate)(int *, int),
	void	(*reverse_rotate)(int *, int),
	void	(*swap)(int *, int)
)
{
	int	is_number_in_top_half;

	is_number_in_top_half = (i <= size / 2);

	// if it's in top half, rotate till it's in [1] and then use swap
	if (is_number_in_top_half)
	{
		while (i > 0)
		{
			if (i == 1)
				swap(stack, size);
			else
				rotate(stack, size);
			i--;
		}
	}

	// else, we'll bring it with rra
	else
	{
		while (i > 0)
		{
			reverse_rotate(stack, size);
			i++;
			if (i == size)
				i = 0;
		}
	}
}

void	place_on_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	n_to_push;
	int	n_to_push_idx;

	n_to_push = *size_b - 1;

	while (*size_b != 0)
	{
		// find n_to_push
		n_to_push_idx = find_n_in_array(stack_b, *size_b, n_to_push);

		// we get n_to_push to the top
		bring_number_to_top(n_to_push_idx, stack_b, *size_b, do_rb, do_rrb, do_sb);

		// push it to a
		do_pa(stack_a, stack_b, size_a, size_b);
	}
}
