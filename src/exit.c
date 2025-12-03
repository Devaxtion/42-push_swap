/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/12/03 15:20:35 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

void	cleanup_and_exit(int status_code, t_stack *a, t_stack *b)
{
	if (status_code != 0)
		write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	exit(status_code);
}
