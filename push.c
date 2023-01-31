/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:59:33 by nugarcia          #+#    #+#             */
/*   Updated: 2023/01/31 17:08:32 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack)
{	
	t_list	*head_b;
	t_list	*new_head_a;
	t_list	*head_a;
	
	if (stack->b == NULL)
		return ;
	head_b = stack->b;
	head_a = stack->a;
	stack->b = head_a;
	stack->a = head_b->prev->next;
	
	ft_printf("pa\n");

}

void	push_b(t_stack *stack)
{
	
}
