/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:29:23 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/09 12:29:23 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_sorted_stack(int *stack, int size)
{
	int	*sorted;

	sorted = ft_calloc(size, sizeof(int));
	if (!sorted)
		cleanup_and_exit(ERR_ALLOC, stack, NULL);
	copy_int_array(sorted, stack, size);
	quicksort(sorted, 0, size - 1);
	return (sorted);
}

void	replace_stack_with_indexes(int *stack_a, int size_a, int *stack_c)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (stack_c[j] != stack_a[i])
			j++;
		stack_a[i] = j;
		i++;
	}
}

void	replace_stack_with_elements(int *stack_a, int size_a, int *stack_c)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		stack_a[i] = stack_c[i];
		i++;
	}
}
