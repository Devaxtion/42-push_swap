/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:05:42 by leramos-          #+#    #+#             */
/*   Updated: 2025/09/16 17:05:42 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

void	error_exit(int status_code, int *stack_a, int *stack_b);
int	is_str_int(char *str);
int	is_int_in_array(int *array, int n);
int	process_args(int argc, char **argv, int *stack);
void	print_int_array(int *array, int size);
void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);

void	swap(int *stack, int size);
void	push(int *stack_dest, int *stack_source, int *size_dest, int *size_source);
void	rotate(int *stack, int size);
void	reverse_rotate(int *stack, int size);

void	swap_a(int *stack_a, int size_a);
void	swap_b(int *stack_b, int size_b);
void	ss(int *stack_a, int *stack_b, int size_a, int size_b);

void	push_a(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	push_b(int *stack_a, int *stack_b, int *size_a, int *size_b);

void	rotate_a(int *stack_a, int size_a);
void	rotate_b(int *stack_b, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);

void	reverse_rotate_a(int *stack_a, int size_a);
void	reverse_rotate_b(int *stack_b, int size_b);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);

#endif