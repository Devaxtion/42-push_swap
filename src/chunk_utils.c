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

int	get_chunk_size(int size_a)
{
	if (size_a <= 100)
		return (size_a / 5 + (size_a % 5 != 0));
	else
		return (size_a / 11 + (size_a % 5 != 0));
}

static int	get_closest_in_chunk(
	int *stack,
	int size,
	int chunk_high
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
		if (stack[i] <= chunk_high)
			return (i);
		if (stack[j] <= chunk_high)
			return (j);
		i++;
	}
	return (-1);
}

void	move_chunk_to_b(t_stack *a, t_stack *b, int chunk_size, int chunk_idx)
{
	int	chunk_high;
	int	chunk_median;
	int	closest_number_idx;

	chunk_high = (chunk_size * (chunk_idx + 1) - 1);
	chunk_median = chunk_high - chunk_size / 2;
	while (1)
	{
		closest_number_idx = get_closest_in_chunk(a->data, a->size, chunk_high);
		if (closest_number_idx == -1)
			break ;
		bring_number_to_top(closest_number_idx, a, do_ra, do_rra);
		place_on_b(a, b, chunk_median);
	}
}
