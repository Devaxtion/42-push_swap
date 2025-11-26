/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:27:57 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:56:00 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_chunk	*create_chunk(int size, int idx)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	chunk->start = size * idx;
	chunk->end = (size * (idx + 1) - 1);
	chunk->median = chunk->start - size / 2;
	chunk->size = size;
	return (chunk);
}

static int	get_chunk_size(int size_a)
{
	if (size_a <= 100)
		return (size_a / 5 + (size_a % 5 != 0));
	else
		return (size_a / 11 + (size_a % 11 != 0));
}

static int	get_num_chunks(int stack_size, int chunk_size)
{
	return ((stack_size / chunk_size) + (stack_size % chunk_size != 0));
}

t_chunk	**init_chunks(t_stack *a)
{
	t_chunk	**chunks;
	int		chunk_size;
	int		num_chunks;
	int		i;

	chunk_size = get_chunk_size(a->size);
	num_chunks = get_num_chunks(a->size, chunk_size);
	chunks = malloc(sizeof(t_chunk *) * (num_chunks + 1));
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < num_chunks)
	{
		chunks[i] = create_chunk(chunk_size, i);
		if (!chunks[i])
		{
			while (--i >= 0)
				free(chunks[i]);
			return (NULL);
		}
		i++;
	}
	chunks[i] = NULL;
	return (chunks);
}

void	free_chunks(t_chunk **chunks)
{
	int	i;

	i = 0;
	while (chunks[i])
	{
		free(chunks[i]);
		i++;
	}
	free(chunks);
}
