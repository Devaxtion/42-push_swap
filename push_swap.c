/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:21:43 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/17 18:21:43 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	int	size_a;
	int	size_b;
	int	status_code;

	// Error: no arguments
	if (argc <= 1)
		error_exit(2, NULL, NULL);

	// Criamos e malocamos um array de ints com a quantidade argc - 1
	size_a = (argc - 1);
	stack_a = malloc(size_a * sizeof(int));
	if (!stack_a)
		error_exit(1, stack_a, NULL);

	// Checkar um a um cada argv e colocar no array, se um deles não é valido, cancela, dá free e dá erro exit
	status_code = process_args(argc, argv, stack_a);
	if (status_code != 0)
		error_exit(status_code, stack_a, NULL);
	
	size_b = 0;
	stack_b = malloc(size_a * sizeof(int));

	print_stacks(stack_a, stack_b, size_a, size_b);
	swap_a(stack_a, size_a);
	print_stacks(stack_a, stack_b, size_a, size_b);
	rotate_a(stack_a, size_a);
	print_stacks(stack_a, stack_b, size_a, size_b);
	reverse_rotate_a(stack_a, size_a);
	print_stacks(stack_a, stack_b, size_a, size_b);
	ft_printf("\n");
	push_b(stack_a, stack_b, &size_a, &size_b);
	print_stacks(stack_a, stack_b, size_a, size_b);
	push_b(stack_a, stack_b, &size_a, &size_b);
	print_stacks(stack_a, stack_b, size_a, size_b);
	push_b(stack_a, stack_b, &size_a, &size_b);
	print_stacks(stack_a, stack_b, size_a, size_b);
	push_b(stack_a, stack_b, &size_a, &size_b);
	print_stacks(stack_a, stack_b, size_a, size_b);

	return (0);
}
