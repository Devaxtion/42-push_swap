/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:14:43 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/13 12:15:28 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of the stack.
// Do nothing if there is only one element or none.
static void	swap(int *stack, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	do_sa(int *stack_a, int size_a)
{
	swap(stack_a, size_a);
	ft_printf("sa\n");
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	do_sb(int *stack_b, int size_b)
{
	swap(stack_b, size_b);
	ft_printf("sb\n");
}

// sa and sb at the same time.
void	do_ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	swap(stack_a, size_a);
	swap(stack_b, size_b);
	ft_printf("ss\n");
}
