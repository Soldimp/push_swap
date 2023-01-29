/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:45 by nuno              #+#    #+#             */
/*   Updated: 2023/01/28 15:53:41 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

int	sorted(t_stack *stack)
{
	t_list	*tmp;
	t_list	*aux;

	tmp = stack->a;
	aux = stack->a->prev->next;
	while (tmp->next != aux)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	//ft_printf("sorted\n");
	return (1);
}