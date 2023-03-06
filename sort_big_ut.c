/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:32:30 by nuno              #+#    #+#             */
/*   Updated: 2023/03/06 16:25:42 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_by_index(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->index >= 0 && stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*get_by_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->content == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
int	find_next_index(t_stack **stack, int previous)
{
	t_stack	*tmp;
	int			current;

	tmp = *stack;
	current = -200000000;
	while (tmp)
	{
		if (tmp->content > previous
			&& ((current == -200000000 && tmp->content != -200000000)
				|| tmp->content < current))
			current = tmp->content;
		tmp = tmp->next;
	}
	return (current);
}

void	give_index(t_stack *tmp, t_stack **stack)
{
	int			i;
	int			current;
	int			previous;

	i = 1;
	while (tmp)
	{
		if (!get_by_index(*stack, i - 1))
		{
			tmp = tmp->next;
			continue ;
		}
		previous = get_by_index(*stack, i - 1)->content;
		current = find_next_index(stack, previous);
		if (!get_by_value(*stack, current))
		{
			tmp = tmp->next;
			continue ;
		}
		get_by_value(*stack, current)->index = i;
		tmp = tmp->next;
		i++;
	}
}

t_stack	*get_lowest(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->content < tmp->content)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

void	init_indexes(t_stack *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

void	pre_asc(t_stack **stack)
{
	t_stack		*tmp;

	init_indexes(*stack);
	get_lowest(*stack)->index = 0;
	tmp = *stack;
	give_index(tmp, stack);
	tmp = *stack;
	while (tmp)
	{
		tmp->content = tmp->index;
		tmp = tmp->next;
	}
}
void	sort_bigger(t_stack **stack_a, t_stack **stack_b)
{
	size_t		length;
	size_t		i;
	size_t		j;
	int			k;

	length = ft_lstsize(*stack_a);
	i = 0;
	pre_asc(stack_a);
	while (!sorted(stack_a))
	{
		j = 0;
		while (j < length)
		{
			k = (*stack_a)->content >> i;
			if ((k & 1) == 1)
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
