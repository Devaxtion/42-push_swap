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