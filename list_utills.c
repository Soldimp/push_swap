/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:21:07 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/28 16:36:08 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack **stack)
{
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

int	ft_lstsize(t_stack *stack)
{
	int			i;
	t_stack		*lstindex;

	i = 0;
	lstindex = stack;
	while (lstindex)
	{
		lstindex = lstindex->next;
		i++;
	}
	return (i);
}

void	free_list(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
