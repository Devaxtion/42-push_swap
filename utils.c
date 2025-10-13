/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:33 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/13 12:36:56 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_and_exit(int status_code, int *stack_a, int *stack_b)
{
	if (status_code != 0)
		ft_printf("Error\n");
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	exit(status_code);
}

int	is_array_sorted(int *array, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (array[i] < array[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_smallest_idx(int *array, int size)
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

void	copy_int_array(int *dest, int *src, int src_size)
{
	int	i;

	i = 0;
	while (i < src_size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	find_n_in_array(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
			return (i);
		i++;
	}
	return (-1);
}
