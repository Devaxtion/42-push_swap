/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:27:57 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/09 12:27:57 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size_a)
{
	if (size_a <= 100)
		return (size_a / 5);
	else
		return (size_a / 11);
}

static int	find_closest_chunk_element(int *stack, int size, int chunk_biggest_number)
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
