/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:45 by nuno              #+#    #+#             */
/*   Updated: 2023/02/08 20:14:42 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "42_print/ft_printf.h"

int	sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	ft_printf("sorted\n");
	return (1);
}

void	sort3(t_stack **stack)
{
	int	biggest;

	if (sorted(stack) == 1)
		return ;
	biggest = biggest_value((*stack));
	if ((*stack)->content == biggest)
		rotate_a(stack);
	else if ((*stack)->next->content == biggest)
		rever_rotate_a(stack);
	if ((*stack)->content > (*stack)->next->content)
		swap_a(stack);
}

static	int smallestValue(t_stack *head) 
{ 
    int min = INT_MAX; 
    while (head != NULL) 
    { 
        if (head->content < min) 
            min = head->content; 
        head = head->next; 
    } 
    return min; 
} 
void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current;
	t_stack	*next;
	int		i;
	int		small;

	small = small_value((*stack_a));
	current = *stack_a;
	next = current->next;
	i = 0;
	while (i < 3 && *stack_a)
	{
		small = small_value((*stack_a));
		current = *stack_a;
		next = current->next;
		while (current)
		{
			if (current->content == small)
			{
				push_b(stack_a, stack_b);
				i++;
				break ;
			}
			current = next;
			if (current != NULL)
				next = current->next;
		}
	}
	//sort3(stack_b);
	/* if (sorted(stack_a) == 0)
		swap_a(stack_a);
	while (*stack_b)
		push_a(stack_b, stack_a); */
	ft_printf("Stack A after moves\n");
	print_list(stack_a);
	ft_printf("Stack b after moves\n");
	print_list(stack_b);
}