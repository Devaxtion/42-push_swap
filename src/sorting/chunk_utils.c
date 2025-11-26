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

static int	is_number_in_chunk(int number, t_chunk chunk)
{
	return (number >= chunk.start && number <= chunk.end);
}

static int	get_closest_in_chunk(t_stack stack, t_chunk chunk)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.size)
	{
		j = (stack.size - 1) - i;
		if (is_number_in_chunk(stack.data[i], chunk))
			return (i);
		if (is_number_in_chunk(stack.data[j], chunk))
			return (j);
		i++;
	}
	return (-1);
}

void	move_chunk_to_b(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int	closest_number_idx;

	while (1)
	{
		closest_number_idx = get_closest_in_chunk(*a, *chunk);
		if (closest_number_idx == -1)
			break ;
		bring_number_to_top(closest_number_idx, a, do_ra, do_rra);
		do_pb(a, b);
		if (b->size > 0 && a->data[0] < chunk->median)
			do_rb(b);
	}
}
