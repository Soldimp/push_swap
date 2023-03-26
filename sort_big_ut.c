/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:32:30 by nuno              #+#    #+#             */
/*   Updated: 2023/03/26 14:54:39 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* radix sort 
bitwise right shift (>>) 
so it starts by checking the lsb(least significant bit)
>> takes two operands - the first operand is the value to be shifted, 
and the second operand is the number of bits to shift it to the right. 
In this case, the value being shifted is the content of the top element of stack_a,
 and the number of bits to shift it to the right is i.
Ex:
1.
stack_a: 5 -> 3 -> 8 -> 1 -> 6
stack_b:

1 = 1
j= 0
lsb = 5 >> 0 = 5 (binary: 101)
5 & 1 = 1, so rotate_a -> stack_a: 3 -> 8 -> 1 -> 6 -> 5
j = 1

lsb = 3 >> 0 = 3 (binary: 11)
3 & 1 = 1, so rotate_a -> stack_a: 8 -> 1 -> 6 -> 5 -> 3
j = 2

lsb = 8 >> 0 = 8 (binary: 1000)
8 & 1 = 0, so push_b -> stack_a: 1 -> 6 -> 5 -> 3; stack_b: 8
j = 3

lsb = 1 >> 0 = 1 (binary: 1)
1 & 1 = 1, so rotate_a -> stack_a: 6 -> 5 -> 3 -> 1; stack_b: 8
j = 4

lsb = 6 >> 0 = 6 (binary: 110)
6 & 1 = 0, so push_b -> stack_a: 5 -> 3 -> 1; stack_b: 8 -> 6

stack_a: 5 -> 3 -> 1
stack_b: 8 -> 6

i = 2
j = 0
lsb = 5 >> 1 = 2 (binary: 10)
2 & 1 = 0, so push_b -> stack_a: 3 -> 1; stack_b: 8 -> 6 -> 5
j = 1

lsb = 3 >> 1 = 1 (binary: 1)
1 & 1 = 1, so rotate_a -> stack_a: 1 -> 3; stack_b: 8 -> 6 -> 5
j = 2

lsb = 1 >> 1 = 0 (binary: 0)
0 & 1 = 0, so push_b -> stack_a: 3; stack_b: 8 -> 6 -> 5 -> 1

stack_a: 3
stack_b: 8 -> 6 -> 5 -> 1

i = 3
j = 0
lsb = 3 >> 2 = 0 (binary: 0)
0 & 1 = 0, so push_b -> stack_a: ; stack_b: 8 -> 6 -> 5 -> 1 -> 3

stack_a:
stack_b: 8 -> 6 -> 5 -> 1 -> 3

final
tack_a: 1 -> 3 -> 5 -> 6 -> 8
stack_b:
*/


void	sort_bigger(t_stack **stack_a, t_stack **stack_b)
{
	size_t	length;
	size_t	i;
	size_t	j;

	length = ft_lstsize(*stack_a);
	i = 0;
	while (!sorted(stack_a))
	{
		j = 0;
		while (j < length)
		{
			if (((*stack_a)->index >> i & 1) == 1)
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
