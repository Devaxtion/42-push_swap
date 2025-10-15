/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:14:43 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/14 12:29:55 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of the stack.
// Do nothing if there is only one element or none.
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = tmp;
	}
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	do_sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	do_sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

// sa and sb at the same time.
void	do_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
