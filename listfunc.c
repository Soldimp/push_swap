/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:52 by nuno              #+#    #+#             */
/*   Updated: 2023/02/02 17:45:00 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

void	print_list(t_stack *stack)
{
	if (!stack)
		return ;
	t_stack *current;
	current = stack;
	while (current != NULL)
	{
		if (current->content) //check for NULL
			printf("%d\n", current->content);
		current = current->next;
	}
}

/* void	*fill_stack_values(t_stack **stack, int n)
{	
	t_stack *new_node;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->content = n;
	new_node->next = *stack;
	*stack = new_node;
} */
