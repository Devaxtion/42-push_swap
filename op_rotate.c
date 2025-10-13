/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:13:49 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/13 12:15:47 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of the stack by 1.
// The first element becomes the last one.
static void	rotate(int *stack, int size)
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

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	do_ra(int *stack_a, int size_a)
{
	rotate(stack_a, size_a);
	ft_printf("ra\n");
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	do_rb(int *stack_b, int size_b)
{
	rotate(stack_b, size_b);
	ft_printf("rb\n");
}

// ra and rb at the same time.
void	do_rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a);
	rotate(stack_b, size_b);
	ft_printf("rr\n");
}
