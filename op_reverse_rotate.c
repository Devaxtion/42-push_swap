/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:15:29 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/14 14:30:24 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of the stack by 1.
// The last element becomes the first one.
static void	reverse_rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->data[stack->size - 1];
	push_elements_down(stack);
	stack->data[0] = tmp;
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	do_rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	do_rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

// rra and rrb at the same time.
void	do_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
