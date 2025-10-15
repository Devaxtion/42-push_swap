/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:14:57 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/14 15:29:22 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shiftes down all elements by 1, essentially leaving the first one repeated
void	push_elements_down(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
}

// Shiftes up all elements by 1, essentially losing the first one
void	push_elements_up(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		stack->data[i - 1] = stack->data[i];
		i++;
	}
}
