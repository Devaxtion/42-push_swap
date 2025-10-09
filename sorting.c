/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:40 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/30 18:32:40 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_2(int *stack_a, int *size_a)
{
    do_sa(stack_a, *size_a);
}

static void sort_3(int *stack_a, int *size_a)
{
    int a;
    int b;
    int c;

    a = stack_a[0];
    b = stack_a[1];
    c = stack_a[2];
    if (a > b && b < c && a < c)
        do_sa(stack_a, *size_a);
    else if (a > b && b > c)
    {
        do_sa(stack_a, *size_a);
        do_rra(stack_a, *size_a);
    }
    else if (a > b && b < c && a > c)
        do_ra(stack_a, *size_a);
    else if (a < b && b > c && a < c)
    {
        do_sa(stack_a, *size_a);
        do_ra(stack_a, *size_a);
    }
    else if (a < b && b > c && a > c)
        do_rra(stack_a, *size_a);
}

/* sort_4_5:
*	Moves the smallest elements till Stack A only has 3 elements.
*	And then calls sort_3 function for Stack A.
*	Moves all elements from B to A.
*/
static void sort_4_5(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	smallest_idx;

    while (*size_a > 3)
    {
        smallest_idx = get_smallest_idx(stack_a, *size_a);
        bring_number_to_top(smallest_idx, stack_a, *size_a, do_ra, do_rra, do_sa);
        do_pb(stack_a, stack_b, size_a, size_b);
    }
    sort_3(stack_a, size_a);
    while (*size_b > 0)
        do_pa(stack_a, stack_b, size_a, size_b);
}

/* big_sorting:
*	Clones Stack A and sorts the clone.
*	Replaces A values with indexes of the values in the cloned Stack (7 1 5 2 9 --> 3 0 2 1 4).
*	Splits Stack A into chunks. For each chunk, find the closest element in the top, and move it to B.
*	In order to save moves, the smallest half of the chunk goes to the bottom of B, while the biggest half goes to the top.
*	When the numbers are all in B, finds the biggest one and pushes to A.
*	When finally all numbers are in A, replaces the values in A (which are indexes of C) with the values in C.
*/
static void	big_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	chunk_size;
	int	chunk_idx;
	int	*stack_c;

	// clone stack A to stack C and sort it
	stack_c = create_sorted_stack(stack_a, *size_a);

	// replace stack A values with indexes of the values in stack C
	replace_stack_with_indexes(stack_a, *size_a, stack_c);

	chunk_size = get_chunk_size(*size_a);
	
	// move chunk by chunk to stack B
	chunk_idx = 0;
	while (*size_a != 0)
	{
		move_chunk_to_b(stack_a, stack_b, size_a, size_b, chunk_size, chunk_idx);
		chunk_idx++;
	}
	place_on_a(stack_a, stack_b, size_a, size_b);
	// replace A indexes with the elements with C
	replace_stack_with_elements(stack_a, *size_a, stack_c);
	free(stack_c);
}

void	sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    if (*size_a == 2)
        sort_2(stack_a, size_a);
    else if (*size_a == 3)
        sort_3(stack_a, size_a);
    else if (*size_a == 4 || *size_a == 5)
        sort_4_5(stack_a, stack_b, size_a, size_b);
	else
		big_sorting(stack_a, stack_b, size_a, size_b);
}