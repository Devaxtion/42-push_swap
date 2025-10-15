/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:32:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:54:37 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	init_stacks(argc, argv, a, b);
	if (!is_array_sorted(a->data, a->size))
		sort(a, b);
	cleanup_and_exit(0, a, b);
	return (0);
}
