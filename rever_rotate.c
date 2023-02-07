/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rever_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:18:08 by nuno              #+#    #+#             */
/*   Updated: 2023/02/07 13:52:34 by nugarcia         ###   ########.fr       */
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
	t_stack	*head;
	t_stack	*last_node;
	t_stack	*befo_last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = get_stack_bottom(*stack);
	befo_last_node = get_node_before_last(*stack);
	head = *stack;
	*stack = last_node;
	(*stack)->next = head;
	befo_last_node->next = NULL;
}

void	rever_rotate_a(t_stack **stack_a)
{	
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rever_rotate_b(t_stack **stack_b)
{	
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rever_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rever_rotate_a(stack_a);
		rever_rotate_b(stack_b);
		ft_printf("rrr\n");
	}
}
