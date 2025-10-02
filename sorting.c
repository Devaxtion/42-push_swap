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

void	small_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	smallest_idx;
	int	i;

	while (*size_a > 0)
	{
		// we look for the smallest number
		smallest_idx = get_smallest_idx(stack_a, *size_a);

		// if index is in the second half, we'll bring it with rra
		if (smallest_idx > *size_a / 2)
		{
			i = 0;
			while (i < (*size_a - smallest_idx))
			{
				do_rra(stack_a, *size_a);
				i++;
			}
			
		}
		// else, we'll bring it with ra
		else
		{
			i = 0;
			while (i < smallest_idx)
			{
				do_ra(stack_a, *size_a);
				i++;
			}
		}
		// now that the smallest number is on top, we push it to b
		do_pb(stack_a, stack_b, size_a, size_b);
	}
	
	while (*size_b > 0)
		do_pa(stack_a, stack_b, size_a, size_b);
}

void	big_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	chunk_size;
	int	chunk_idx;
	int	closest_number_idx;
	int	*stack_c;
	int	chunk_biggest_number;
	int	chunk_median;

	// clone stack A to stack C and sort it
	stack_c = ft_calloc(*size_a, sizeof(int));
	clone_stack(stack_c, stack_a, *size_a);
	quicksort(stack_c, 0, *size_a - 1);

	// replace stack A values with indexes of the values in stack C
	replace_stack_with_indexes(stack_a, *size_a, stack_c);

	chunk_size = get_chunk_size(*size_a);
	
	// move chunk by chunk to stack B
	chunk_idx = 0;
	while (*size_a != 0)
	{
		chunk_biggest_number = (chunk_size * (chunk_idx + 1) - 1);
		chunk_median = chunk_biggest_number - chunk_size / 2;

		// Move chunk to Stack B
		// “Does stack A still contain at least one element in the current chunk range?”
		while (1)
		{
			// find the closest number to the top or bottom (from current chunk)
			closest_number_idx = find_closest_chunk_element(stack_a, *size_a, chunk_biggest_number);
			if (closest_number_idx == -1)
				break;

			// Put it on top
			bring_number_to_top(closest_number_idx, stack_a, *size_a, do_ra, do_rra, do_sa);

			// Place the number on B
			place_on_b(stack_a, stack_b, size_a, size_b, chunk_median);
		}
		// Next chunk
		chunk_idx++;
	}

	// push everything to A
	place_on_a(stack_a, stack_b, size_a, size_b);

	// replace A numbers with C
	replace_stack_with_numbers(stack_a, *size_a, stack_c);
	free(stack_c);
}






// void	old_big_sorting(int *stack_a, int *stack_b, int *size_a, int *size_b)
// {
// 	int	chunk_size;
// 	int	chunk_idx;
// 	int	closest_number_idx;
// 	int	*stack_c;

// 	// create and allocate a new stack C with the same size
// 	// ft_printf("- Creating Stack C... ");
// 	stack_c = ft_calloc(*size_a, sizeof(int));
// 	// ft_printf("Done!\n");

// 	// clone the stack A to it
// 	// ft_printf("- Cloning the Stack A to C... ");
// 	clone_stack(stack_c, stack_a, *size_a);
// 	// ft_printf("Done!\n");

// 	// sort the new stack C
// 	// ft_printf("- Sorting the Stack C... ");
// 	quicksort(stack_c, 0, *size_a - 1);
// 	// ft_printf("Done!\n");

// 	// replace stack A values with indexes of the values in stack C
// 	// ft_printf("- Replacing stack A values with indexes of the values in stack C... ");
// 	replace_stack_with_indexes(stack_a, *size_a, stack_c);
// 	// ft_printf("Done!\n");

// 	// print_stack(stack_a, *size_a, 'A');
// 	// ft_printf("\n");

// 	// get the chunk size
// 	chunk_size = get_chunk_size(*size_a);
// 	// ft_printf("- Chunk Size = %i\n", chunk_size);
	
// 	// move chunk by chunk to stack B
// 	chunk_idx = 0;
// 	while (*size_a != 0)
// 	{
// 		// Move chunk to Stack B
// 		// “Does stack A still contain at least one element in the current chunk range?”
// 		while (find_closest_chunk_element(stack_a, *size_a, chunk_size, chunk_idx) != -1)
// 		{
// 			// ft_printf("- Start while: Chunk Index = %i\n", chunk_idx);
// 			// print_stacks(stack_a, stack_b, *size_a, *size_b);
// 			// find the closest number to the top or bottom (from current chunk)
// 			closest_number_idx = find_closest_chunk_element(stack_a, *size_a, chunk_size, chunk_idx);
// 			// ft_printf("- Closest number (idx) = %i\n", closest_number_idx);

// 			// Put it on top
// 			bring_number_to_top(closest_number_idx, stack_a, size_a);
// 			// ft_printf("- Brought number %i to top\n", stack_a[0]);
// 			// print_stacks(stack_a, stack_b, *size_a, *size_b);

// 			// Place the number on B
// 			place_on_b(stack_a, stack_b, size_a, size_b);
// 			// ft_printf("- Placed on B\n");
// 			// print_stacks(stack_a, stack_b, *size_a, *size_b);
// 		}
// 		// Next chunk
// 		chunk_idx++;
// 	}
// 	// push everything to A
// 	while (*size_b != 0)
// 		do_pa(stack_a, stack_b, size_a, size_b);
// 	// replace A numbers with C
// 	replace_stack_with_numbers(stack_a, *size_a, stack_c);
// 	// free C
// 	free(stack_c);
// }
