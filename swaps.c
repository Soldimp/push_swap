/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/07 11:35:37 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	swap_a(t_stack **stack_a)
{
	swap((*stack_a));
	ft_printf("sa\n");
}	

void	swap_b(t_stack **stack_b)
{
	swap((*stack_b));
	ft_printf("sb\n");
}

void	swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		swap((*stack_a));
		swap((*stack_b));
		ft_printf("ss\n");
	}
}
