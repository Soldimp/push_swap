/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:42:39 by nuno              #+#    #+#             */
/*   Updated: 2023/01/28 15:59:28 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
				exit(write(2, "Error\n", 6));
		if (i == 1)
			stack_a =  ft_lstnew((int)nb);
		else
			ft_lstadd_back(&stack_a, ft_lstnew((int)nb));
		i++;
	}
	return (stack_a);
} */
static void	how_to_sort(int ac, t_stack *stack)
{
	if (sorted(stack) == 1)
		return ;
}

void	push_swap(int ac, char **av)
{
	t_stack stack;
	int		i;

	i = 1;
	stack.a = NULL;
	stack.b = NULL;

	while (i < ac)
		{
			stack.a = fill_stack_values(&stack.a, ft_atoi2(av[i]));
			i++;
		}
	ft_printf("Stack A\n");
	print_list(stack.a);
	while (i < ac)
		{
			stack.b = fill_stack_values(&stack.b, ft_atoi2(av[i]));
			i++;
		}
	print_list(stack.b);
	how_to_sort(ac, &stack);
	//free(stack.a);.
	//free(stack.b);

}

int	main(int ac, char **av)
{
	/* t_stack	*stack_a;
	t_stack	*stack_b;
 */
	if (ac < 2)
		return (0);
	if (checkvalid_iput(ac, av) == FALSE)
		exit(write(2, "Error\n", 6));
	push_swap(ac, av);
	return 0;
}