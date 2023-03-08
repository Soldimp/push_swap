/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/03/07 16:56:23 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_stack;

////////		List creation and print		////////	
t_stack		*fill_stack_values(int ac, char **av);
void		print_list(t_stack **stack);

////////		List Funcions		////////	
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*stack_new(int nb);
void		ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack		*get_node_before_last(t_stack *head);
int			ft_lstsize(t_stack *stack);
void		free_list(t_stack **stack);

////////		Inputs		////////
int			checkvalid_iput(int ac, char **av);
int			checker_sinal(int ac, char **av);
int			checker_max_min(int ac, char **a);
int			onlynumbers(int ac, char **av);
int			dupnub(int ac, char **av);

////////		Atoi	////////	
long long	ft_atoi2(const char *str);

////////		Push_swap stack filling	////////	
void		push_swap(t_stack **stack_a, t_stack **stack_b);

////////		Sorting				////////	
int			sorted(t_stack **stack);
void		sort3(t_stack **stack_a);
void		sort4_5(t_stack **stack_a, t_stack **stack_b);
void		sort_big(t_stack **stack_a, t_stack **stack_b);


////////		Sorting	Utills			////////	
int			biggest_value(t_stack *stack);
int			smallestvalues(t_stack *stack);
void		check_pos(t_stack **stack_a, t_stack **stack_b, int c, int n);

////////		Sorting	Big Utills			////////	
void		sort_bigger(t_stack **stack_a, t_stack **stack_b);

////////		Swaps			////////	
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_a_b(t_stack **stack_a, t_stack **stack_b);

////////		Push			////////	
void		push_a(t_stack **stack_b, t_stack **stack_a);
void		push_b(t_stack **stack_a, t_stack **stack_b);

////////		Rotates			////////	
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_a_b(t_stack **stack_a, t_stack **stack_b);
////////		Reverse Rotates		////////	
void		rever_rotate_a(t_stack **stack_a);
void		rever_rotate_b(t_stack **stack_b);
void		rever_rotate_a_b(t_stack **stack_a, t_stack **stack_b);
#endif
