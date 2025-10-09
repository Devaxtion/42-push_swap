/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:10:47 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/30 18:10:47 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *array, int low, int high)
{
	int pivot;
	int i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quicksort(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high);
		quicksort(array, low, pivot_idx - 1);
		quicksort(array, pivot_idx + 1, high);
	}
}
