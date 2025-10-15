/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:02:52 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:04:40 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int_array(int *array, int size)
{
	int	i;

	ft_printf("[");
	i = 0;
	while (i < size)
	{
		ft_printf("%d", array[i]);
		if (i < size - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}

void	print_stack(t_stack *stack, char l)
{
	ft_printf("Stack %c (%i): ", l, stack->size);
	print_int_array(stack->data, stack->size);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, 'A');
	print_stack(b, 'B');
	ft_printf("\n");
}
