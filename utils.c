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

void	cleanup_and_exit(int status_code, int *stack_a, int *stack_b)
{
	if (status_code != 0)
		ft_printf("Error %i\n", status_code);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	exit(status_code);
}

