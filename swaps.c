/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/03/15 13:17:30 by nugarcia         ###   ########.fr       */
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
	write(1, "sa\n", 3);
}	

void	swap_b(t_stack **stack_b)
{
	swap((*stack_b));
	write(1, "sb\n", 3);
}

void	swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		swap((*stack_a));
		swap((*stack_b));
		write(1, "ss\n", 3);
	}
}
