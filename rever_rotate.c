/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rever_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:18:08 by nuno              #+#    #+#             */
/*   Updated: 2023/03/15 14:49:18 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checks if the stack is empty or has only one node 
get_stack_bottom to get a pointer to the last node of the stack
get_node_before_last to get a pointer to the node before the last node.

save head node so to put head node to be the last node and 
update the next pointer of the 
last node to be the head node. 
update the next pointer of 
the node before the last node to be NULL, 
effectively removing it from the linked list.
*/

static	void	reverse_rotate(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	first = *stack;
	*stack = last->next;
	last->next = NULL;
	(*stack)->next = first;
}

void	rever_rotate_a(t_stack **stack_a)
{	
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rever_rotate_b(t_stack **stack_b)
{	
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rever_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rever_rotate_a(stack_a);
		rever_rotate_b(stack_b);
		write(1, "rrr\n", 4);
	}
}
