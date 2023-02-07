/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:21:07 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/07 13:48:29 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if (current->content) //check for NULL */
void	print_list(t_stack **stack)
{
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		//if (current->content)
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

int	ft_lstsize(t_stack **stack)
{
	int			i;
	t_stack		*lstindex;

	i = 0;
	lstindex = *stack;
	while (lstindex)
	{
		lstindex = lstindex->next;
		i++;
	}
	return (i);
}

void	index_on_stack(t_stack **stack_a, int size)
{
	t_stack	*head;
	t_stack	*biggest;
	int		value;

	while (--size > 0)
	{
		head = *stack_a;
		value = INT_MIN;
		biggest = NULL;
		while (head)
		{
			if (head->content == INT_MIN && head->index == 0)
				head->index = 1;
			if (head->content > value && head->index == 0)
			{
				value = head->content;
				biggest = head;
				head = *stack_a;
			}
			else
				head = head->next;
		}
		if (biggest != NULL)
			biggest->index = size;
	}
}
