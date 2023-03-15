/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:52 by nuno              #+#    #+#             */
/*   Updated: 2023/03/15 13:16:50 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi2(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit(write(2, "Error\n", 6));
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			ft_lstadd_back(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* Creation of a new stack */

t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nb;
	new->next = NULL;
	return (new);
}

/* Addition of a new node to an existing stack. */

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* Adds an element to the bottom of a stack. */
void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*las_node;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	las_node = get_stack_bottom(*stack);
	las_node->next = new;
}
