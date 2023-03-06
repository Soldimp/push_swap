/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:12:32 by nuno              #+#    #+#             */
/*   Updated: 2023/02/20 16:56:51 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  head is where the first node off the stack his saved
	so i can then update the stack to the secode node doing that removing the 
	head.

    last_node where i save the las node by using get_stack_bottom.

    The next pointer of the head node is set to NULL, which means 
	it is no longer part of the stack.
    The next pointer of the last node is set to head, putting the 
	head to last */

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	last_node = get_stack_bottom(*stack);
	head->next = NULL;
	last_node->next = head;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
