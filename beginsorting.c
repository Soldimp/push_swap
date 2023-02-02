/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:45 by nuno              #+#    #+#             */
/*   Updated: 2023/02/02 16:39:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

int	sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;

	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	ft_printf("sorted\n");
	return (1);
}
