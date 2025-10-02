/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:33 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/30 18:32:33 by leramos-         ###   ########.fr       */
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

int	is_int_in_array(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int		get_smallest_idx(int *array, int size)
{
	int	smallest_idx;
	int	i;

	smallest_idx = 0;
	i = 1;
	while (i < size)
	{
		if (array[i] < array[smallest_idx])
			smallest_idx = i;
		i++;
	}
	return (smallest_idx);
}

static void	print_int_array(int *array, int size)
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

void	print_stack(int *stack, int size, char l)
{
	ft_printf("Stack %c (%i): ", l, size);
	print_int_array(stack, size);
}

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
{
	print_stack(stack_a, size_a, 'A');
	print_stack(stack_b, size_b, 'B');
	ft_printf("\n");
}
