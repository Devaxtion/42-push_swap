/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:43:58 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:17:24 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If number it's in top half, Rotate till it's in 2nd slot and then use Swap
// If it's in bottom half, bring it with Reverse Rotate
void	bring_number_to_top(
	int idx,
	t_stack *stack,
	void (*rotate)(t_stack *),
	void (*reverse_rotate)(t_stack *)
)
{
	int	moves_needed;

	if (idx <= stack->size / 2)
	{
		moves_needed = idx;
		while (moves_needed > 0)
		{
			rotate(stack);
			moves_needed--;
		}
	}
	else
	{
		moves_needed = stack->size - idx;
		while (moves_needed > 0)
		{
			reverse_rotate(stack);
			moves_needed--;
		}
	}
}

void	place_on_b(t_stack *a, t_stack *b, int chunk_median)
{
	if (b->size == 0 || a->data[0] >= chunk_median)
		do_pb(a, b);
	else
	{
		do_pb(a, b);
		do_rb(b);
	}
}

void	place_on_a(t_stack *a, t_stack *b)
{
	int	n_to_push;
	int	n_to_push_idx;

	while (b->size != 0)
	{
		n_to_push = b->size - 1;
		n_to_push_idx = find_n_in_array(b->data, b->size, n_to_push);
		bring_number_to_top(n_to_push_idx, b, do_rb, do_rrb);
		do_pa(a, b);
	}
}
