/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:45 by nuno              #+#    #+#             */
/*   Updated: 2023/02/07 14:59:56 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

static	int	biggest_value(t_stack *stack)
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

int	sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	ft_printf("sorted\n");
	return (1);
}

void	sort3(t_stack **stack)
{
	int	biggest;

	if (sorted(stack) == 1)
		return ;
	biggest = biggest_value((*stack));
	if ((*stack)->content == biggest)
		rotate_a(stack);
	else if ((*stack)->next->content == biggest)
		rever_rotate_a(stack);
	if ((*stack)->content > (*stack)->next->content)
		swap_a(stack);
}

void	sort5(t_stack **stack)
{
	
}