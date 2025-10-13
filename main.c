/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/13 14:07:10 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_int_array(int *array, int size)
// {
// 	int	i;

// 	ft_printf("[");
// 	for (i = 0; i < size; i++)
// 	{
// 		ft_printf("%d", array[i]);
// 		if (i < size - 1)
// 			ft_printf(", ");
// 	}
// 	ft_printf("]\n");
// }

// static void	print_stack(int *stack, int size, char l)
// {
// 	ft_printf("Stack %c (%i): ", l, size);
// 	print_int_array(stack, size);
// }

// void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
// {
// 	print_stack(stack_a, size_a, 'A');
// 	print_stack(stack_b, size_b, 'B');
// 	ft_printf("\n");
// }

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	init_stacks(argc, argv, &stack_a, &stack_b, &size_a, &size_b);
	if (!is_array_sorted(stack_a, size_a))
		sort(stack_a, stack_b, &size_a, &size_b);
	// print_stacks(stack_a, stack_b, size_a, size_b);
	cleanup_and_exit(0, stack_a, stack_b);
	return (0);
}
