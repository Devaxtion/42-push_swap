/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:22:15 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/25 13:22:15 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	print_stacks(stack_a, stack_b, *size_a, *size_b);
	swap_a(stack_a, *size_a);
	print_stacks(stack_a, stack_b, *size_a, *size_b);
	rotate_a(stack_a, *size_a);
	print_stacks(stack_a, stack_b, *size_a, *size_b);
	reverse_rotate_a(stack_a, *size_a);
	print_stacks(stack_a, stack_b, *size_a, *size_b);
	ft_printf("\n");
	// push_b(stack_a, stack_b, size_a, size_b);
	// print_stacks(stack_a, stack_b, *size_a, *size_b);
	// push_b(stack_a, stack_b, size_a, size_b);
	// print_stacks(stack_a, stack_b, *size_a, *size_b);
	// push_b(stack_a, stack_b, size_a, size_b);
	// print_stacks(stack_a, stack_b, *size_a, *size_b);
	// push_b(stack_a, stack_b, size_a, size_b);
	// print_stacks(stack_a, stack_b, *size_a, *size_b);
}

void	small_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	smallest_idx;
	int	i;

	while (*size_a > 0)
	{
		// we look for the smallest number
		smallest_idx = get_smallest_idx(stack_a, *size_a);

		// if index is in the second half, we'll bring it with rra
		if (smallest_idx > *size_a / 2)
		{
			i = 0;
			while (i < (*size_a - smallest_idx))
			{
				reverse_rotate_a(stack_a, *size_a);
				i++;
			}
			
		}
		// else, we'll bring it with ra
		else
		{
			i = 0;
			while (i < smallest_idx)
			{
				rotate_a(stack_a, *size_a);
				i++;
			}
		}
		// now that the smallest number is on top, we push it to b
		push_b(stack_a, stack_b, size_a, size_b);
	}
	
	while (*size_b > 0)
		push_a(stack_a, stack_b, size_a, size_b);
}

int	get_chunk_size(int size_a)
{
	return (sqrt(size_a));
}

void	big_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	chunk_size;
	int	chunk_idx;
	int	closest_number_idx;
	int	*stack_c;
	// create and allocate a new stack C with the same size
	stack_c = ft_calloc(&size_a, sizeof(int));
	// clone the stack A to it
	clone_stack(stack_c, stack_a, &size_a);
	// sort the new stack C
	;
	// replace stack A values with indexes of the values in stack C
	replace_stack_with_indexes(stack_a, &size_a, stack_c);

	// get the chunk size = sqrt(n);
	chunk_size = get_chunk_size(size_a);
	
	// move chunk by chunk to stack B
	chunk_idx = 0;
	while (chunk_size * chunk_idx < *size_a + chunk_size)
	{
		// Move chunk to Stack B
		while (*size_a != 0)
		{
			// find the closest number to the top or bottom (from current chunk)
			closest_number_idx = find_closest_number(stack_a, &size_a, chunk_size, chunk_idx);

			// Put it on top
			bring_number_to_top(closest_number_idx, stack_a, size_a);

			// Place the number on B
			place_on_b(stack_a, stack_b, size_a, size_b);
		}
		// Next chunk
		chunk_idx++;
	}
	// push everything to A
	while (*size_b != 0)
		push_a(stack_a, stack_b, size_a, size_b);
	// replace A numbers with C
	replace_stack_with_numbers(stack_a, &size_a, stack_c);
	// free C
	free(stack_c);
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

int	is_stack_b_sorted(int *stack_b, int *size_b)
{
	int	i;

	i = 1;
	while (i < *size_b)
	{
		if (stack_b[i - 1] < stack_b[i])
			return (0);
		i++;
	}
	return (1);
}

void	place_on_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	// if there is nothing on B, just push B
	if (*size_b == 0)
		return (push_b(stack_a, stack_b, size_a, size_b));

	// if there is numbers on B:
	// if A[0] > B[0], push B
	if (stack_a[0] > stack_b[0])
		return (push_b(stack_a, stack_b, size_a, size_b));

	// else,			 (if A[0] > B[0]),
	else
	{
		//	- if A[0] < B[last]
		//		- push B
		//		- rotate B
		if (stack_a[0] < stack_b[*size_b - 1])
		{
			push_b(stack_a, stack_b, size_a, size_b);
			rotate_b(stack_b, &size_b);
		}
		//	- else,         (if A[0] > B[last]),
		//		- rotate B até A[0] estiver entre B[0] e B[last] //// rotate B até A[0] > B[0]
		//		- push B
		//		- reverse rotate B a quantidade de vezes que fizemos antes //// reverse rotate B até A[0] > B[last]
		else
		{
			while (stack_a[0] < stack_b[0])
				rotate_b(stack_b, &size_b);
			push_b(stack_a, stack_b, size_a, size_b);
			while (stack_a[0] > stack_b[*size_b - 1])
				reverse_rotate_b(stack_b, &size_b);

		}
	}

}

void	bring_number_to_top(int n_idx, int *stack_a, int *size_a)
{
	int	n;
	int	number_is_in_first_half;

	// while (stack_a[0] != stack_a[n_idx])
	// while (n_idx != 0)
	n = stack_a[n_idx];
	number_is_in_first_half = n_idx <= *size_a / 2;
	while (stack_a[0] != n)
	{
		// if index is in the first half, we'll bring it with rr
		if (number_is_in_first_half)
			rotate_a(stack_a, *size_a);
		// else, we'll bring it with rra
		else
			reverse_rotate_a(stack_a, *size_a);
	}
}



int	find_closest_number(int *stack_a, int size_a, int chunk_size, int chunk_idx)
{
	int	i;
	int	j;
	int	chunk_end;

	chunk_end = chunk_size * (chunk_idx + 1) - 1;
	i = 0;
	while (i != size_a / 2)
	{
		j = size_a - 1 - i;
		if (stack_a[i] <= chunk_end)
			return (i);
		if (stack_a[j] <= chunk_end)
			return (j);
		i++;
	}
	return (-1);
}
