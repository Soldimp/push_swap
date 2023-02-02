/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/02 17:49:06 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int temp;

	if (stack == NULL || stack->next == NULL)
		return ;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	ft_printf("sa\n");
	
}	

void	swap_b(t_stack *stack)
{
	int temp;

	if (stack == NULL || stack->next == NULL)
		return ;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	ft_printf("sb\n");
	
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b)
	{
		swap_a(stack_a);
		swap_b(stack_b);
		ft_printf("ss\n");
	}
}
