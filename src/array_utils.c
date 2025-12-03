/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:36:48 by leramos-          #+#    #+#             */
/*   Updated: 2025/12/03 15:22:38 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_arraydup(int *src, int size)
{
	int	*dst;
	int	i;

	if (!src || size <= 0)
		return (NULL);
	dst = malloc(size * sizeof(int));
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

int	ft_strarraylen(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}
