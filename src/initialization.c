/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:09:47 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/25 15:28:22 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_sign(char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
		if (!**str)
			return (0);
	}
	return (1);
}

static int	is_int_valid(char *str)
{
	int			i;
	long long	num;
	int			sign;

	if (!str || !str[0])
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	if (!process_sign(&str, &sign))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > (long long)INT_MAX + 1))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_args_to_stack(char **argv, t_stack *stack)
{
	int	i;
	int	int_to_add;

	i = 0;
	while (i < stack->size)
	{
		if (!is_int_valid(argv[i + 1]))
			return (ERR_INVALID_INT);
		int_to_add = ft_atoi(argv[i + 1]);
		if (find_n_in_array(stack->data, i, int_to_add) != -1)
			return (ERR_DUPLICATE);
		stack->data[i] = int_to_add;
		i++;
	}
	return (0);
}

static void	allocate_stacks(int argc, t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	if (!*a)
		cleanup_and_exit(ERR_ALLOC, NULL, NULL);
	*b = malloc(sizeof(t_stack));
	if (!*b)
		cleanup_and_exit(ERR_ALLOC, *a, NULL);
	(*a)->size = argc - 1;
	(*a)->data = ft_calloc((*a)->size, sizeof(int));
	if (!(*a)->data)
		cleanup_and_exit(ERR_ALLOC, *a, NULL);
	(*b)->size = 0;
	(*b)->data = ft_calloc((*a)->size, sizeof(int));
	if (!(*b)->data)
		cleanup_and_exit(ERR_ALLOC, *a, *b);
}

void	init_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	status_code;

	if (argc < 2)
		cleanup_and_exit(0, NULL, NULL);
	allocate_stacks(argc, a, b);
	status_code = parse_args_to_stack(argv, *a);
	if (status_code != 0)
		cleanup_and_exit(status_code, *a, *b);
}
