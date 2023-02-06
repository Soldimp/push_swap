/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:42:39 by nuno              #+#    #+#             */
/*   Updated: 2023/02/06 17:46:13 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	how_to_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (sorted(stack_a) == 1)
		return ;
	if (size == 2 && !sorted(stack_a))
	{
		swap_a(stack_a);
		sorted(stack_a);
	}
	else if (size == 3 && !sorted(stack_a))
	{

	}
	else if (size > 3 && !sorted(stack_a))
	{
		
	}
}

static	void free_list(t_stack **stack)
{
    t_stack *current = *stack;
    t_stack *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_lstsize(stack_a);
	ft_printf("Stack A before moves\n");
	print_list(stack_a);
	ft_printf("||||||||Moves|||||||\n");
	ft_printf("||||||||||||||||||||\n");

	how_to_sort (stack_a, stack_b, size);
	//ft_lstsize(stack_a);
	ft_printf("Stack A after moves\n");
	print_list(stack_a);
	
	free_list(stack_a);
	//free_list(stack_b);
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
