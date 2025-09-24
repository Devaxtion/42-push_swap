/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:32:56 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/23 14:32:56 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	swap_a(int *stack_a, int size_a)
{
	swap(stack_a, size_a);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	swap_b(int *stack_b, int size_b)
{
	swap(stack_b, size_b);
}

// sa and sb at the same time.
void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	swap(stack_a, size_a);
	swap(stack_b, size_b);
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	push_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	push(stack_a, stack_b, size_a, size_b);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	push(stack_b, stack_a, size_b, size_a);
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(int *stack_a, int size_a)
{
	rotate(stack_a, size_a);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(int *stack_b, int size_b)
{
	rotate(stack_b, size_b);
}

// ra and rb at the same time.
void	rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate_a(stack_a, size_a);
	rotate_b(stack_b, size_b);
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_rotate_a(int *stack_a, int size_a)
{
	reverse_rotate(stack_a, size_a);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	reverse_rotate_b(int *stack_b, int size_b)
{
	reverse_rotate(stack_b, size_b);
}

// rra and rrb at the same time.
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate_a(stack_a, size_a);
	reverse_rotate_b(stack_b, size_b);
}
