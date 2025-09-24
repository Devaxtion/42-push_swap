/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:32:51 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/23 14:32:51 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of the stack
// Do nothing if there is only one element or none
void	swap(int *stack, int size)
{
    int	temp;

	if (size > 1)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

// Take the first element at the top of src and put it at the top of dest
// Do nothing if src is empty
void	push(int *dest, int *src, int *dest_size, int *src_size)
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

// Shift up all elements of the stack by 1
// The first element becomes the last one
void	rotate(int *stack, int size)
{
	int	i;
	int	temp;

	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

// Shift down all elements of the stack by 1
// The last element becomes the first one
void	reverse_rotate(int *stack, int size)
{
	int	i;
	int	temp;

	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}
