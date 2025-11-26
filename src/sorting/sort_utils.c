/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:27:57 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:56:00 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_encode(int *stack_to_encode, int size, int *sorted_stack)
{
	int	i;
	int	idx;

	i = 0;
	while (i < size)
	{
		idx = find_n_in_array(sorted_stack, size, stack_to_encode[i]);
		stack_to_encode[i] = idx;
		i++;
	}
}

void	rank_decode(int *stack_to_decode, int size, int *sorted_stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_to_decode[i] = sorted_stack[stack_to_decode[i]];
		i++;
	}
}

// If number it's in top half, Rotate till it's on top
// If it's in bottom half, bring it with Reverse Rotate till it's on top
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

void	place_on_a(t_stack *a, t_stack *b)
{
	int	highest_nbr;
	int	highest_nbr_idx;

	while (b->size != 0)
	{
		highest_nbr = b->size - 1;
		highest_nbr_idx = find_n_in_array(b->data, b->size, highest_nbr);
		bring_number_to_top(highest_nbr_idx, b, do_rb, do_rrb);
		do_pa(a, b);
	}
}
