/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:13:49 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/14 14:29:32 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of the stack by 1.
// The first element becomes the last one.
static void	rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->data[0];
	push_elements_up(stack);
	stack->data[stack->size - 1] = tmp;
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	do_ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	do_rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

// ra and rb at the same time.
void	do_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
