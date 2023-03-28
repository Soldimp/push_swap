/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:32:30 by nuno              #+#    #+#             */
/*   Updated: 2023/03/28 12:58:15 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bigger(t_stack **stack_a, t_stack **stack_b)
{
	size_t	length;
	size_t	i;
	size_t	j;

	length = ft_lstsize(*stack_a);
	i = 0;
	while (!sorted(stack_a))
	{
		j = 0;
		while (j < length)
		{
			if (((*stack_a)->index >> i & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while ((*stack_b))
			push_a(stack_b, stack_a);
		i++;
	}
}
