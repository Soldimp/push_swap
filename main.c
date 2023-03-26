/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:42:39 by nuno              #+#    #+#             */
/*   Updated: 2023/03/26 14:57:59 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	how_to_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (sorted(stack_a) == TRUE)
		return ;
	if (size == 2 && !sorted(stack_a))
	{
		swap_a(stack_a);
		sorted(stack_a);
	}
	else if (size == 3 && !sorted(stack_a))
	{
		sort3(stack_a);
		sorted(stack_a);
	}
	else if (size == 4 || (size == 5 && !sorted(stack_a)))
	{
		sort4_5(stack_a, stack_b);
		sorted(stack_a);
	}
	else if (size > 5 && !sorted(stack_a))
	{
		sort_big(stack_a, stack_b);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(stack_a);
	sort_bigger(stack_a, stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	how_to_sort (stack_a, stack_b, size);
	free_list(stack_a);
	free_list(stack_b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (ac < 2)
		return (0);
	if (checkvalid_iput(ac, av) == FALSE)
		exit(write(2, "Error\n", 6));
	stack_a = fill_stack_values(ac, av);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
}
