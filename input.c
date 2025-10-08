/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:09:47 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/07 16:09:47 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int_valid(char *str)
{
	int		i;
	long long	num;

	if (!str || !str[0])
		return (0);
	i = 0;
	num = 0;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if (num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	array_contains_int(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

static int	parse_args_to_stack(char **argv, int *stack, int size)
{
	int	i;
	int	int_to_add;

	i = 0;
	while (i < size)
	{
		if (!is_int_valid(argv[i + 1]))
			return (ERR_INVALID_INT);
		int_to_add = ft_atoi(argv[i + 1]);
		if (array_contains_int(stack, size, int_to_add))
			return (ERR_DUPLICATE);
		stack[i] = int_to_add;
		i++;
	}
	return (0);
}

void	init_stacks(int argc, char **argv, int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	status_code;

	if (argc <= 1)
		cleanup_and_exit(0, NULL, NULL);
	*size_a = (argc - 1);
	*stack_a = ft_calloc(*size_a, sizeof(int));
	if (!*stack_a)
		cleanup_and_exit(ERR_ALLOC, *stack_a, NULL);

	status_code = parse_args_to_stack(argv, *stack_a, *size_a);
	if (status_code != 0)
		cleanup_and_exit(status_code, *stack_a, NULL);
	
	*size_b = 0;
	*stack_b = ft_calloc(*size_a, sizeof(int));
	if (!*stack_b)
		cleanup_and_exit(ERR_ALLOC, *stack_a, *stack_b);
}
