/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/01/31 14:42:43 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	aux;

	if (stack->a)
	{
		aux = stack->a->content;
		stack->a->content = stack->a->next->content;
		stack->a->next->content = aux;
		ft_printf("sa\n");
	}
}	

void	swap_b(t_stack *stack)
{
	int	aux;

	if (stack->b)
	{
		aux = stack->b->content;
		stack->b->content = stack->b->next->content;
		stack->b->next->content = aux;
		ft_printf("sb\n");
	}
}

void	swap_a_b(t_stack *stack)
{
	if (stack->a && stack->b)
	{
		swap_a(stack);
		swap_b(stack);
		ft_printf("ss\n");
	}
}
