/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:40 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 11:51:28 by leramos-         ###   ########.fr       */
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
*	Moves the smallest elements till Stack A only has 3 elements.
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
*	Clones Stack A and sorts the clone.
*	Replaces A values with indexes of the values in the cloned Stack (7 1 5 2 9 --> 3 0 2 1 4).
*	Splits Stack A into chunks. For each chunk, find the closest element in the top, and move it to B.
*	In order to save moves, the smallest half of the chunk goes to the bottom of B, while the biggest half goes to the top.
*	When the numbers are all in B, finds the biggest one and pushes to A.
*	When finally all numbers are in A, replaces the values in A (which are indexes of C) with the values in C.
*/
static void	big_sorting(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_idx;
	int	*sorted_stack;

	sorted_stack = create_sorted_stack(a->data, a->size);
	if (!sorted_stack)
		cleanup_and_exit(ERR_ALLOC, a, b);
	replace_stack_with_indexes(a->data, a->size, sorted_stack);
	chunk_size = get_chunk_size(a->size);
	chunk_idx = 0;
	while (a->size != 0)
	{
		move_chunk_to_b(a, b, chunk_size, chunk_idx);
		chunk_idx++;
	}
	place_on_a(a, b);
	replace_stack_with_elements(a->data, a->size, sorted_stack);
	free(sorted_stack);
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
