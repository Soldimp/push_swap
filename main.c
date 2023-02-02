/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:42:39 by nuno              #+#    #+#             */
/*   Updated: 2023/02/02 18:00:57 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	how_to_sort(int ac, t_stack *stack)
{
	if (sorted(stack) == 1)
		return ;
}
/* loop is used to allocate memory for the linked list elements and 
fill them with values from the input array av. The loop runs ac - 1 times, 
as i starts at 1 and ends when i becomes equal to ac.
Memory is allocated for a new node in the linked list using malloc and stored in 
a->next.

The pointer a is then moved to the newly allocated node using a = a->next.

 The value of the new node is set to ft_atoi2(av[i]), which is the integer value 
 of the i-th element of av.

 The next node in the linked list is set to NULL using a->next = NULL.
 The value of i is incremented by 1.

This loop is used to add all the values from av to the linked list a. 
At the end of the loop, 
the linked list will contain all the values from av. */
void *create_malloc(size_t size) 
{
  void *ptr = malloc(size);
  if (!ptr) {
    // handle malloc failure
    exit(1);
  }
  return ptr;
}
void	push_swap(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;

	a = create_malloc(sizeof(t_stack));
	a->next = NULL;
	head_a = a;
	b = create_malloc(sizeof(t_stack));
	b->next = NULL;
	head_b = b;
	i = 1;
	while (i < ac)
	{
		a->next = create_malloc(sizeof(t_stack));
		a = a->next;
		a->content = ft_atoi2(av[i]);
		a->next = NULL;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		b->next = create_malloc(sizeof (t_stack));
		b = b->next;
		if (i == 0)
			b->content = 15;
		if (i == 1)
			b->content = 20;
		if (i == 2)
			b->content = 25;
		b->next = NULL;
		i++;
	}
	ft_printf("Stack A before any move\n");
	print_list(head_a);
	//swap_a(head_a->next);
	swap_a_b(head_a->next, head_b->next);
	ft_printf("Stack A After \n");
	print_list(head_a);
	ft_printf("Stack B before any move\n");
	print_list(head_b);
	ft_printf("Stack B After\n");
	print_list(head_b);
	//free(stack.a);
	//free(stack.b);
	//how_to_sort(ac, head_a);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (checkvalid_iput(ac, av) == FALSE)
		exit(write(2, "Error\n", 6));
	push_swap(ac, av);
	return (0);
}
