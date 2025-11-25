/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:29:23 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/25 14:30:51 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_stackdup(int *src, int size)
{
	int	*dst;
	int	i;

	dst = ft_calloc(size, sizeof(int));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	rank_encode(int *stack_to_encode, int size, int *sorted_stack)
{
	int	i;
	int	idx;

	i = 0;
	while (i < size)
	{
		idx = find_n_in_array(sorted_stack, size, stack_to_encode[i]);
		stack_to_encode[i] = idx;
		i++;
	}
}

void	rank_decode(int *stack_to_decode, int size, int *sorted_stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_to_decode[i] = sorted_stack[stack_to_decode[i]];
		i++;
	}
}
