/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:35:51 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/13 15:52:18 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_100(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack;
	int		small;
	int		size_stack;
	int		vals;
	int		sizehalf;

	sizehalf = ft_lstsize(stack_a) / 2;
	vals = 0;
	tmp_stack = *stack_a;
	size_stack = 0;
	
	while (vals < 50 && size_stack )
	{
		
		vals++;
	}
}
