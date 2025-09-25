/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:15:53 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/24 14:15:53 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0: no error / no arguments
// 1: other errors
// 2: argument has to only have integers
// 3: argument has duplicates
void	error_exit(int status_code, int *stack_a, int *stack_b)
{
	if (status_code != 0)
		ft_printf("Error %i\n", status_code);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	exit(status_code);
}

int	is_str_int(char *str)
{
	int i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int_in_array(int *array, int n)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	process_args(int argc, char **argv, int *stack)
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
		if (is_int_in_array(stack, int_to_add))
			return (3);
		
		// Add to the stack
		stack[i] = int_to_add;

		i++;
	}

	return (0);
}

void	print_int_array(int *array, int size)
{
    int	i;

    ft_printf("[");
    for (i = 0; i < size; i++)
    {
        ft_printf("%d", array[i]);
        if (i < size - 1)
            ft_printf(", ");
    }
    ft_printf("]\n");
}

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
{
	ft_printf("Stack A (%i): ", size_a);
	print_int_array(stack_a, size_a);
	ft_printf("Stack B (%i): ", size_b);
	print_int_array(stack_b, size_b);
	ft_printf("\n");
}