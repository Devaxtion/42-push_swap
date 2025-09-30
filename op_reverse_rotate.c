/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:15:29 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/30 18:15:29 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of the stack by 1.
// The last element becomes the first one.
static void	reverse_rotate(int *stack, int size)
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

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	do_rra(int *stack_a, int size_a)
{
	reverse_rotate(stack_a, size_a);
	ft_printf("rra\n");
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	do_rrb(int *stack_b, int size_b)
{
	reverse_rotate(stack_b, size_b);
	ft_printf("rrb\n");
}

// rra and rrb at the same time.
void	do_rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate(stack_a, size_a);
	reverse_rotate(stack_b, size_b);
	ft_printf("rrr\n");
}
