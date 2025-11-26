/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:40 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/25 15:20:12 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack *a)
{
	do_sa(a);
}

static void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->data[0];
	y = a->data[1];
	z = a->data[2];
	if (x > y && y < z && x < z)
		do_sa(a);
	else if (x > y && y > z)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (x > y && y < z && x > z)
		do_ra(a);
	else if (x < y && y > z && x < z)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (x < y && y > z && x > z)
		do_rra(a);
}

/* sort_4_5:
*	Moves the smallest elements to B till Stack A only has 3 elements.
*	And then calls sort_3 function for Stack A.
*	Moves all elements from B to A.
*/
static void	sort_4_5(t_stack *a, t_stack *b)
{
	int	smallest_idx;

	while (a->size > 3)
	{
		smallest_idx = get_smallest_idx(a->data, a->size);
		bring_number_to_top(smallest_idx, a, do_ra, do_rra);
		do_pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		do_pa(a, b);
}

/* big_sorting:
*	Converts stack values to their sorted positions.
*	Processes chunks: moves numbers to B in chunks, optimizing placement.
*	Smaller half of the chunk goes to bottom of B, larger to top.
*	When done, moves all numbers back to A in sorted order.
*	Restores original values from sorted reference.
*/

static void	big_sorting(t_stack *a, t_stack *b)
{
	t_chunk	**chunks;
	int		*stack_tmp;
	int		i;

	stack_tmp = ft_arraydup(a->data, a->size);
	if (!stack_tmp)
		cleanup_and_exit(ERR_ALLOC, a, b);
	quicksort(stack_tmp, 0, a->size - 1);
	rank_encode(a->data, a->size, stack_tmp);
	chunks = init_chunks(a);
	if (!chunks)
		cleanup_and_exit(ERR_ALLOC, a, b);
	i = 0;
	while (chunks[i])
	{
		move_chunk_to_b(a, b, chunks[i]);
		i++;
	}
	place_on_a(a, b);
	rank_decode(a->data, a->size, stack_tmp);
	free(stack_tmp);
	free_chunks(chunks);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_4_5(a, b);
	else
		big_sorting(a, b);
}
