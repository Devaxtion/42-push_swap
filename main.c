/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/30 18:32:44 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

static int	process_args(int argc, char **argv, int *stack, int size)
{
	int	i;
	int	int_to_add;

	i = 0;
	while (i < argc - 1) // args = nameprogram 20 30 40 50 60 // argc = 6
	{
		// check if string only has integers
		if (!is_str_int(argv[i + 1])) // 20
			return (2);
		
		// TODO check if string is inside limits

		// convert from str to int
		int_to_add = ft_atoi(argv[i + 1]);

		// Error: it's a duplicate
		if (is_int_in_array(stack, size, int_to_add))
			return (3);
		
		// Add to the stack
		stack[i] = int_to_add;

		i++;
	}

	return (0);
}

int	main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	int	size_a;
	int	size_b;
	int	status_code;

	// Error: no arguments
	if (argc <= 1)
		error_exit(0, NULL, NULL);

	// Criamos e malocamos um array de ints com a quantidade argc - 1
	size_a = (argc - 1);
	stack_a = ft_calloc(size_a, sizeof(int));
	if (!stack_a)
		error_exit(1, stack_a, NULL);

	// Checkar um a um cada argv e colocar no array, se um deles não é valido, cancela, dá free e dá erro exit
	status_code = process_args(argc, argv, stack_a, size_a);
	if (status_code != 0)
		error_exit(status_code, stack_a, NULL);
	
	size_b = 0;
	stack_b = ft_calloc(size_a, sizeof(int));

	// start operations
	// test_sorting(stack_a, stack_b, &size_a, &size_b);
	print_stacks(stack_a, stack_b, size_a, size_b);
	if (size_a <= 5 || size_a >= 5)
		small_sorting(stack_a, stack_b, &size_a, &size_b);
	print_stacks(stack_a, stack_b, size_a, size_b);

	error_exit(0, stack_a, stack_b);
	return (0);
}
