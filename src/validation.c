/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:35:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/12/03 15:38:12 by leramos-         ###   ########.fr       */
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

int	is_int_valid(char *str)
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
