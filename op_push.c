/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:13:46 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/30 18:13:46 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of src and put it at the top of dest.
// Do nothing if src is empty.
static void	push(int *dest, int *src, int *dest_size, int *src_size)
{
	int	i;

	if (*src_size == 0)
		return ;

	// push all dest elements down to leave space for ELEMENT
	// only if dest isn't empty
	i = *dest_size - 1; // starts on index of last element
	while (i >= 0)
	{
		dest[i + 1] = dest[i];
		i--;
	}

	// move ELEMENT to top of dest
	dest[0] = src[0];
	(*dest_size)++;

	// push all the src elements up to fill the empty space
	i = 1; // start on the second element
	while (i < *src_size)
	{
		src[i - 1] = src[i];
		i++;
	}

	// deletes the last element since it was pushed upwards / moved to dest
	src[*src_size - 1] = '\0';
	(*src_size)--;
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	do_pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	push(stack_a, stack_b, size_a, size_b);
	ft_printf("pa\n");
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	do_pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	push(stack_b, stack_a, size_b, size_a);
	ft_printf("pb\n");
}
