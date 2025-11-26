/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:27:57 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:56:00 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_closest_in_chunk(
	int *stack,
	int size,
	int chunk_end
)
{
	int	i;
	int	j;

	if (size <= 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		j = size - 1 - i;
		if (stack[i] <= chunk_end)
			return (i);
		if (stack[j] <= chunk_end)
			return (j);
		i++;
	}
	return (-1);
}

void	move_chunk_to_b(t_stack *a, t_stack *b, t_chunk chunk)
{
	int	closest_number_idx;

	while (1)
	{
		closest_number_idx = get_closest_in_chunk(a->data, a->size, chunk.end);
		if (closest_number_idx == -1)
			break ;
		bring_number_to_top(closest_number_idx, a, do_ra, do_rra);
		if (b->size == 0 || a->data[0] >= chunk.median)
			do_pb(a, b);
		else
		{
			do_pb(a, b);
			do_rb(b);
		}
	}
}
