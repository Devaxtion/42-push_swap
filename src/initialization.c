/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:09:47 by leramos-          #+#    #+#             */
/*   Updated: 2025/12/03 15:37:57 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_values_to_stack(char **values, t_stack *stack)
{
	int		i;
	int		int_to_add;

	i = 0;
	while (i < stack->size)
	{
		if (!is_int_valid(values[i]))
			return (ERR_INVALID_INT);
		int_to_add = ft_atoi(values[i]);
		if (find_n_in_array(stack->data, i, int_to_add) != -1)
			return (ERR_DUPLICATE);
		stack->data[i] = int_to_add;
		i++;
	}
	return (0);
}

static void	allocate_stacks(int size, t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	if (!*a)
		cleanup_and_exit(ERR_ALLOC, NULL, NULL);
	*b = malloc(sizeof(t_stack));
	if (!*b)
		cleanup_and_exit(ERR_ALLOC, *a, NULL);
	(*a)->size = size;
	(*a)->data = ft_calloc((*a)->size, sizeof(int));
	if (!(*a)->data)
		cleanup_and_exit(ERR_ALLOC, *a, NULL);
	(*b)->size = 0;
	(*b)->data = ft_calloc((*a)->size, sizeof(int));
	if (!(*b)->data)
		cleanup_and_exit(ERR_ALLOC, *a, *b);
}

static char	**parse_args(int *size, int ac, char **av)
{
	char	**values;

	values = NULL;
	if (ac == 2)
	{
		values = ft_split(av[1], ' ');
		if (!values)
			cleanup_and_exit(0, NULL, NULL);
		*size = ft_strarraylen(values);
	}
	else
	{
		values = av + 1;
		*size = ac - 1;
	}
	if (*size == 0)
	{
		if (ac == 2)
			free_str_array(values);
		cleanup_and_exit(ERR_INVALID_INT, NULL, NULL);
	}
	return (values);
}

void	init_stacks(int ac, char **av, t_stack **a, t_stack **b)
{
	char	**values;
	int		size;
	int		status_code;

	if (ac < 2)
		cleanup_and_exit(0, NULL, NULL);
	values = parse_args(&size, ac, av);
	allocate_stacks(size, a, b);
	status_code = parse_values_to_stack(values, *a);
	if (ac == 2)
		free_str_array(values);
	if (status_code != 0)
		cleanup_and_exit(status_code, *a, *b);
}
