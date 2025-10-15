/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:13:46 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/14 14:28:38 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of src and put it at the top of dest.
// Do nothing if src is empty.
static void	push(t_stack *dest, t_stack *src)
{
	if (src->size == 0)
		return ;
	dest->size++;
	push_elements_down(dest);
	dest->data[0] = src->data[0];
	push_elements_up(src);
	src->size--;
}

void	do_pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	do_pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pb\n");
}
