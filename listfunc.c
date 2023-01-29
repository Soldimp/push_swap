/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:52 by nuno              #+#    #+#             */
/*   Updated: 2023/01/28 16:00:26 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

void	print_list(t_list *stack)
{
	t_list	*tmp;
	t_list	*aux;

	if (!stack)
		return ;
	tmp = stack;
	aux = stack->next;
	ft_printf("%d\n", stack->content);
	while (aux && aux != tmp)
	{
		ft_printf("%d\n", aux->content);
		aux = aux->next;
	}
}

t_list	*fill_stack_values(t_list **stack, int n)
{
	t_list	*head;
	t_list	*tmp;

	head= malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->content = n;
	if (!*stack)
	{
		*stack = head;
		head->prev = *stack;
		head->next = *stack;
		return (*stack);
	}
	tmp = (*stack)->prev;
	(*stack)->prev = head;
	head->prev = tmp;
	tmp->next = head;
	head->next = (*stack);
	return (*stack);
}
