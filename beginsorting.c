/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:45 by nuno              #+#    #+#             */
/*   Updated: 2023/02/09 17:58:19 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

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

void	sort4_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *values_po;
	int		small;
	int		size;
	
	size = ft_lstsize(stack_a);
	if (size == 5)
	{
		values_po = *stack_a;
		small = smallestValues(values_po);
		check_pos(stack_a, stack_b, small, 1);
	}
	values_po = *stack_a;
	small = smallestValues(values_po);
	check_pos(stack_a, stack_b, small, 2);
	if (sorted(stack_a) == 0)
		sort3(stack_a);
	while (*stack_b)
		push_a(stack_b, stack_a); 
}
