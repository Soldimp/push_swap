/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort utills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:53 by nuno              #+#    #+#             */
/*   Updated: 2023/02/08 20:01:12 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_value(t_stack *stack)
{
	int	value;

	value = stack->content;
	while (stack)
	{
		if (stack->content > value)
			value = stack->content;
		stack = stack->next;
	}
	return (value);
}

int	small_value(t_stack *stack_a)
{
	int	value;

	value =  stack_a->content;
	while (stack_a != NULL)
	{
		if (stack_a->content < value)
			value = stack_a->content;
		stack_a = stack_a->next;
	}
	return (value);
}