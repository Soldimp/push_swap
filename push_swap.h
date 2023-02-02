/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:06 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/02 18:31:13 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include "42_print/ft_printf.h"

# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_stack;

////////		Memory Allocate	////////
void *create_malloc(size_t size);

////////		List creation and print		////////	
//void		*fill_stack_values(t_stack **stack, int n);//not needed
void		print_list(t_stack *stack);

////////		List Funcions		////////	
/* void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(void *content);
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstadd_front(t_stack **lst, t_stack *new); */

/home/nuno/.ssh/id_ed25519.pub
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIFjPRZ7gOG5tkhyvuGapzdN8e9CSDosecRpvOjfbpgnp
////////		Inputs		////////
int			checkvalid_iput(int ac, char **av);
int			checker_sinal(int ac, char **av);
int			checker_max_min(int ac, char **a);
int			onlynumbers(int ac, char **av);
int			dupnub(int ac, char **av);

////////		Atoi	////////	
long long	ft_atoi2(const char *str);


////////		Push_swap stack filling	////////	
void		push_swap(int ac, char **av);

////////		Sorting				////////	
int			sorted(t_stack *stack);

////////		Swaps			////////	
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_a_b(t_stack *stack_a, t_stack *stack_b);

////////		Push			////////	
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
#endif

