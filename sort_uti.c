/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_uti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:53 by nuno              #+#    #+#             */
/*   Updated: 2023/03/15 14:49:48 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_value(t_stack *stack)
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

/* Use the temp_stack to traverse through the linked list
stack and compare each node's content with the small node's content. 
If temp_stack's content is smaller than small's content, update small 
to point to 
temp_stack.
After finding the node with the smallest value, initialize temp_stack to 
stack again and traverse through the linked list using temp_stack until 
temp_stack reaches small.
For every node visited in this step, increment the c counter.
Return the value of c, which is the position of the smallest value in the 
linked list. */

int	smallestvalues(t_stack *stack)
{
	t_stack	*temp_stack;
	t_stack	*small;
	int		i;

	temp_stack = stack;
	small = stack;
	i = 0;
	while (temp_stack)
	{
		if (small->content > temp_stack->content)
			small = temp_stack;
		temp_stack = temp_stack->next;
	}
	temp_stack = stack;
	while (temp_stack != small)
	{
		i++;
		temp_stack = temp_stack->next;
	}
	return (i);
}

/* checks the position of the smallest value in stack_a by 
comparing the values of each node. If the position is greater than 2, 
it rotates the elements of stack_a in reverse direction by a number of times 
specified by c. If the position is less than or equal to 2, the function 
rotates the elements of stack_a in the forward direction by c number of times. 
Finally, the function pushes the smallest value from stack_a to stack_b. */

/* checks if the value of "c" is greater than 2. If it is, then the value of 
"c" is either set to 5 sminus "c" (when n is equal to 1) or 4 minus "c" 
(when n is not equal to 1). 
value of "c" in order to correctly rotate the elements in stack_a to get the 
desired element in the
first position for push_b.*/

void	check_pos(t_stack **stack_a, t_stack **stack_b, int c, int n)
{
	if (c > 2)
	{
		if (n == 1)
			c = 5 - c;
		else
			c = 4 - c;
		while (c != 0)
		{
			rever_rotate_a(stack_a);
			c--;
		}
	}
	else
	{
		while (c != 0)
		{
			rotate_a(stack_a);
			c--;
		}
	}
	push_b(stack_a, stack_b);
}
