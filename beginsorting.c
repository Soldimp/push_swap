/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:45 by nuno              #+#    #+#             */
/*   Updated: 2023/03/08 16:47:04 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* this funcion works for 4 or 5 numbers
Works by finding the smallest values and sending the 2 smallest values to
funcion check_pos
First if is to get the smallest value so i send the stacks and the value
and also sending that this is the first number so in th funcion check_pos
i find what position the smallest values are located and perform the correct 
moves by sending th smallest to the top of stack_a so then
i send only 2 values to stack_b already in descending order
and stack_a i just call my sort3 to order it ascending and then i just need to 
do 2 push_a and stack_a has now all the numbers in order this is for 5 numbers
for 4 numbers i just send 1 value to check_pos so then i just us my sort3 and 
the just
push_a once   */

void	sort4_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*values_po;
	int		small;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size == 5)
	{
		values_po = *stack_a;
		small = smallestvalues(values_po);
		check_pos(stack_a, stack_b, small, 1);
	}
	values_po = *stack_a;
	small = smallestvalues(values_po);
	check_pos(stack_a, stack_b, small, 2);
	if (sorted(stack_a) == FALSE)
		sort3(stack_a);
	while (*stack_b)
		push_a(stack_b, stack_a);
}
