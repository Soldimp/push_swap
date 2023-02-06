/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:52 by nuno              #+#    #+#             */
/*   Updated: 2023/02/06 17:37:30 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

void	print_list(t_stack **stack)
{
	if (!*stack)
		return ;
	t_stack *current;
	current = *stack;
	while (current != NULL)
	{
		if (current->content) //check for NULL
			ft_printf("%d\n", current->content);
		current = current->next;
	}
}

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
			exit(write(2,"Error\n", 6));
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

/* Returns the node that is just before the last node of the linked list. */
t_stack	*get_node_before_last(t_stack *head) 
{
    t_stack *current;
    t_stack *next;

	current = head;
	next = head->next;
    while (next->next != NULL) 
	{
        current = next;
        next = next->next;
    }
    return current;
}

int	ft_lstsize(t_stack **stack)
{
	int			i;
	t_stack		*lstindex;

	i = 0;
	lstindex = *stack;
	while (lstindex)
	{
		lstindex = lstindex->next;
		i++;
	}
	ft_printf("size: %d\n", i);
	return (i);
}